/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "RSPDefinitions"
 * 	found in "../../../asn1/rsp.asn"
 * 	`asn1c -fwide-types -fcompound-names -fincludes-quoted -no-gen-example`
 */

#include "InitiateAuthenticationRequest.h"

asn_TYPE_member_t asn_MBR_InitiateAuthenticationRequest_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct InitiateAuthenticationRequest, euiccChallenge),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Octet16,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"euiccChallenge"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct InitiateAuthenticationRequest, smdpAddress),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UTF8String,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"smdpAddress"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct InitiateAuthenticationRequest, euiccInfo1),
		(ASN_TAG_CLASS_CONTEXT | (32 << 2)),
		0,
		&asn_DEF_EUICCInfo1,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"euiccInfo1"
		},
};
static const ber_tlv_tag_t asn_DEF_InitiateAuthenticationRequest_tags_1[] = {
	(ASN_TAG_CLASS_CONTEXT | (57 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_InitiateAuthenticationRequest_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 0, 0, 0 }, /* euiccChallenge */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 1, 0, 0 }, /* smdpAddress */
    { (ASN_TAG_CLASS_CONTEXT | (32 << 2)), 2, 0, 0 } /* euiccInfo1 */
};
asn_SEQUENCE_specifics_t asn_SPC_InitiateAuthenticationRequest_specs_1 = {
	sizeof(struct InitiateAuthenticationRequest),
	offsetof(struct InitiateAuthenticationRequest, _asn_ctx),
	asn_MAP_InitiateAuthenticationRequest_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_InitiateAuthenticationRequest = {
	"InitiateAuthenticationRequest",
	"InitiateAuthenticationRequest",
	&asn_OP_SEQUENCE,
	asn_DEF_InitiateAuthenticationRequest_tags_1,
	sizeof(asn_DEF_InitiateAuthenticationRequest_tags_1)
		/sizeof(asn_DEF_InitiateAuthenticationRequest_tags_1[0]) - 1, /* 1 */
	asn_DEF_InitiateAuthenticationRequest_tags_1,	/* Same as above */
	sizeof(asn_DEF_InitiateAuthenticationRequest_tags_1)
		/sizeof(asn_DEF_InitiateAuthenticationRequest_tags_1[0]), /* 2 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_InitiateAuthenticationRequest_1,
	3,	/* Elements count */
	&asn_SPC_InitiateAuthenticationRequest_specs_1	/* Additional specs */
};

