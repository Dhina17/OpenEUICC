/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "RSPDefinitions"
 * 	found in "../../../asn1/rsp.asn"
 * 	`asn1c -fwide-types -fcompound-names -fincludes-quoted -no-gen-example`
 */

#include "AuthenticateResponseError.h"

asn_TYPE_member_t asn_MBR_AuthenticateResponseError_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct AuthenticateResponseError, transactionId),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TransactionId,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"transactionId"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct AuthenticateResponseError, authenticateErrorCode),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_AuthenticateErrorCode,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"authenticateErrorCode"
		},
};
static const ber_tlv_tag_t asn_DEF_AuthenticateResponseError_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_AuthenticateResponseError_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 1, 0, 0 }, /* authenticateErrorCode */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* transactionId */
};
asn_SEQUENCE_specifics_t asn_SPC_AuthenticateResponseError_specs_1 = {
	sizeof(struct AuthenticateResponseError),
	offsetof(struct AuthenticateResponseError, _asn_ctx),
	asn_MAP_AuthenticateResponseError_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_AuthenticateResponseError = {
	"AuthenticateResponseError",
	"AuthenticateResponseError",
	&asn_OP_SEQUENCE,
	asn_DEF_AuthenticateResponseError_tags_1,
	sizeof(asn_DEF_AuthenticateResponseError_tags_1)
		/sizeof(asn_DEF_AuthenticateResponseError_tags_1[0]), /* 1 */
	asn_DEF_AuthenticateResponseError_tags_1,	/* Same as above */
	sizeof(asn_DEF_AuthenticateResponseError_tags_1)
		/sizeof(asn_DEF_AuthenticateResponseError_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_AuthenticateResponseError_1,
	2,	/* Elements count */
	&asn_SPC_AuthenticateResponseError_specs_1	/* Additional specs */
};

