/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "RSPDefinitions"
 * 	found in "../../../asn1/rsp.asn"
 * 	`asn1c -fwide-types -fcompound-names -fincludes-quoted -no-gen-example`
 */

#include "ListNotificationResponse.h"

static asn_oer_constraints_t asn_OER_type_ListNotificationResponse_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_ListNotificationResponse_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_notificationMetadataList_2[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_CONTEXT | (47 << 2)),
		0,
		&asn_DEF_NotificationMetadata,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_notificationMetadataList_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_notificationMetadataList_specs_2 = {
	sizeof(struct ListNotificationResponse__notificationMetadataList),
	offsetof(struct ListNotificationResponse__notificationMetadataList, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_notificationMetadataList_2 = {
	"notificationMetadataList",
	"notificationMetadataList",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_notificationMetadataList_tags_2,
	sizeof(asn_DEF_notificationMetadataList_tags_2)
		/sizeof(asn_DEF_notificationMetadataList_tags_2[0]) - 1, /* 1 */
	asn_DEF_notificationMetadataList_tags_2,	/* Same as above */
	sizeof(asn_DEF_notificationMetadataList_tags_2)
		/sizeof(asn_DEF_notificationMetadataList_tags_2[0]), /* 2 */
	{ 0, 0, SEQUENCE_OF_constraint },
	asn_MBR_notificationMetadataList_2,
	1,	/* Single element */
	&asn_SPC_notificationMetadataList_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ListNotificationResponse_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ListNotificationResponse, choice.notificationMetadataList),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_notificationMetadataList_2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"notificationMetadataList"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ListNotificationResponse, choice.listNotificationsResultError),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_INTEGER,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"listNotificationsResultError"
		},
};
static const ber_tlv_tag_t asn_DEF_ListNotificationResponse_tags_1[] = {
	(ASN_TAG_CLASS_CONTEXT | (40 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ListNotificationResponse_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* notificationMetadataList */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* listNotificationsResultError */
};
static asn_CHOICE_specifics_t asn_SPC_ListNotificationResponse_specs_1 = {
	sizeof(struct ListNotificationResponse),
	offsetof(struct ListNotificationResponse, _asn_ctx),
	offsetof(struct ListNotificationResponse, present),
	sizeof(((struct ListNotificationResponse *)0)->present),
	asn_MAP_ListNotificationResponse_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0,
	2	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_ListNotificationResponse = {
	"ListNotificationResponse",
	"ListNotificationResponse",
	&asn_OP_CHOICE,
	asn_DEF_ListNotificationResponse_tags_1,
	sizeof(asn_DEF_ListNotificationResponse_tags_1)
		/sizeof(asn_DEF_ListNotificationResponse_tags_1[0]), /* 1 */
	asn_DEF_ListNotificationResponse_tags_1,	/* Same as above */
	sizeof(asn_DEF_ListNotificationResponse_tags_1)
		/sizeof(asn_DEF_ListNotificationResponse_tags_1[0]), /* 1 */
	{ &asn_OER_type_ListNotificationResponse_constr_1, &asn_PER_type_ListNotificationResponse_constr_1, CHOICE_constraint },
	asn_MBR_ListNotificationResponse_1,
	2,	/* Elements count */
	&asn_SPC_ListNotificationResponse_specs_1	/* Additional specs */
};

