package im.angry.openeuicc.ui

import android.annotation.SuppressLint
import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.content.IntentFilter
import android.hardware.usb.UsbManager
import android.os.Bundle
import android.telephony.TelephonyManager
import android.util.Log
import android.view.Menu
import android.view.MenuItem
import android.view.View
import android.widget.ProgressBar
import androidx.fragment.app.Fragment
import androidx.lifecycle.lifecycleScope
import androidx.viewpager2.adapter.FragmentStateAdapter
import androidx.viewpager2.widget.ViewPager2
import com.google.android.material.tabs.TabLayout
import com.google.android.material.tabs.TabLayoutMediator
import im.angry.openeuicc.common.R
import im.angry.openeuicc.util.*
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext

@SuppressLint("NotifyDataSetChanged")
open class MainActivity : BaseEuiccAccessActivity(), OpenEuiccContextMarker {
    companion object {
        const val TAG = "MainActivity"
    }

    private lateinit var loadingProgress: ProgressBar
    private lateinit var tabs: TabLayout
    private lateinit var viewPager: ViewPager2

    private var refreshing = false

    private data class Page(
        val title: String,
        val createFragment: () -> Fragment
    )

    private val pages: MutableList<Page> = mutableListOf()

    private val pagerAdapter by lazy {
        object : FragmentStateAdapter(this) {
            override fun getItemCount() = pages.size

            override fun createFragment(position: Int): Fragment = pages[position].createFragment()
        }
    }

    protected lateinit var tm: TelephonyManager

    private val usbReceiver = object : BroadcastReceiver() {
        override fun onReceive(context: Context?, intent: Intent?) {
            if (intent?.action == UsbManager.ACTION_USB_DEVICE_ATTACHED || intent?.action == UsbManager.ACTION_USB_DEVICE_DETACHED) {
                refresh(true)
            }
        }
    }

    @SuppressLint("WrongConstant", "UnspecifiedRegisterReceiverFlag")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        setSupportActionBar(requireViewById(R.id.toolbar))
        loadingProgress = requireViewById(R.id.loading)
        tabs = requireViewById(R.id.main_tabs)
        viewPager = requireViewById(R.id.view_pager)

        viewPager.adapter = pagerAdapter
        TabLayoutMediator(tabs, viewPager) { tab, pos ->
            tab.text = pages[pos].title
        }.attach()

        tm = telephonyManager

        supportActionBar?.setDisplayHomeAsUpEnabled(true)

        registerReceiver(usbReceiver, IntentFilter().apply {
            addAction(UsbManager.ACTION_USB_DEVICE_ATTACHED)
            addAction(UsbManager.ACTION_USB_DEVICE_DETACHED)
        })
    }

    override fun onDestroy() {
        super.onDestroy()
        unregisterReceiver(usbReceiver)
    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        menuInflater.inflate(R.menu.activity_main, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean =
        when (item.itemId) {
            R.id.settings -> {
                startActivity(Intent(this, SettingsActivity::class.java));
                true
            }
            R.id.reload -> {
                refresh()
                true
            }
            android.R.id.home -> {
                onBackPressed()
                true
            }
            else -> super.onOptionsItemSelected(item)
        }

    override fun onInit() {
        lifecycleScope.launch {
            init()
        }
    }

    private suspend fun init(fromUsbEvent: Boolean = false) {
        refreshing = true // We don't check this here -- the check happens in refresh()
        loadingProgress.visibility = View.VISIBLE
        viewPager.visibility = View.GONE
        tabs.visibility = View.GONE

        val knownChannels = withContext(Dispatchers.IO) {
            euiccChannelManager.enumerateEuiccChannels().onEach {
                Log.d(TAG, "slot ${it.slotId} port ${it.portId}")
                Log.d(TAG, it.lpa.eID)
                // Request the system to refresh the list of profiles every time we start
                // Note that this is currently supposed to be no-op when unprivileged,
                // but it could change in the future
                euiccChannelManager.notifyEuiccProfilesChanged(it.logicalSlotId)
            }
        }

        val (usbDevice, _) = withContext(Dispatchers.IO) {
            euiccChannelManager.enumerateUsbEuiccChannel()
        }

        withContext(Dispatchers.Main) {
            loadingProgress.visibility = View.GONE

            knownChannels.sortedBy { it.logicalSlotId }.forEach { channel ->
                pages.add(Page(
                    getString(R.string.channel_name_format, channel.logicalSlotId)
                ) { appContainer.uiComponentFactory.createEuiccManagementFragment(channel) })
            }

            // If USB readers exist, add them at the very last
            // We use a wrapper fragment to handle logic specific to USB readers
            usbDevice?.let {
                pages.add(Page(it.productName ?: getString(R.string.usb)) { UsbCcidReaderFragment() })
            }
            viewPager.visibility = View.VISIBLE

            if (pages.size > 1) {
                tabs.visibility = View.VISIBLE
            } else if (pages.isEmpty()) {
                pages.add(Page("") { appContainer.uiComponentFactory.createNoEuiccPlaceholderFragment() })
            }

            pagerAdapter.notifyDataSetChanged()
            // Reset the adapter so that the current view actually gets cleared
            // notifyDataSetChanged() doesn't cause the current view to be removed.
            viewPager.adapter = pagerAdapter

            if (fromUsbEvent && usbDevice != null) {
                // If this refresh was triggered by a USB insertion while active, scroll to that page
                viewPager.post {
                    viewPager.setCurrentItem(pages.size - 1, true)
                }
            } else {
                viewPager.currentItem = 0
            }

            refreshing = false
        }
    }

    private fun refresh(fromUsbEvent: Boolean = false) {
        if (refreshing) return
        lifecycleScope.launch {
            refreshing = true
            loadingProgress.visibility = View.VISIBLE
            viewPager.visibility = View.GONE
            tabs.visibility = View.GONE

            pages.clear()
            pagerAdapter.notifyDataSetChanged()
            viewPager.adapter = pagerAdapter

            init(fromUsbEvent) // will set refreshing = false
        }
    }
}
