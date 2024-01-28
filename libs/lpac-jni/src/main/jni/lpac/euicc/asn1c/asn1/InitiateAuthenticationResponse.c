/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "RSPDefinitions"
 * 	found in "../../../asn1/rsp.asn"
 * 	`asn1c -fwide-types -fcompound-names -fincludes-quoted -no-gen-example`
 */

#include "InitiateAuthenticationResponse.h"

static asn_oer_constraints_t asn_OER_type_InitiateAuthenticationResponse_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_InitiateAuthenticationResponse_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_InitiateAuthenticationResponse_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct InitiateAuthenticationResponse, choice.initiateAuthenticationOk),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_InitiateAuthenticationOkEs9,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"initiateAuthenticationOk"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct InitiateAuthenticationResponse, choice.initiateAuthenticationError),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_INTEGER,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"initiateAuthenticationError"
		},
};
static const ber_tlv_tag_t asn_DEF_InitiateAuthenticationResponse_tags_1[] = {
	(ASN_TAG_CLASS_CONTEXT | (57 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_InitiateAuthenticationResponse_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* initiateAuthenticationOk */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* initiateAuthenticationError */
};
asn_CHOICE_specifics_t asn_SPC_InitiateAuthenticationResponse_specs_1 = {
	sizeof(struct InitiateAuthenticationResponse),
	offsetof(struct InitiateAuthenticationResponse, _asn_ctx),
	offsetof(struct InitiateAuthenticationResponse, present),
	sizeof(((struct InitiateAuthenticationResponse *)0)->present),
	asn_MAP_InitiateAuthenticationResponse_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0,
	2	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_InitiateAuthenticationResponse = {
	"InitiateAuthenticationResponse",
	"InitiateAuthenticationResponse",
	&asn_OP_CHOICE,
	asn_DEF_InitiateAuthenticationResponse_tags_1,
	sizeof(asn_DEF_InitiateAuthenticationResponse_tags_1)
		/sizeof(asn_DEF_InitiateAuthenticationResponse_tags_1[0]), /* 1 */
	asn_DEF_InitiateAuthenticationResponse_tags_1,	/* Same as above */
	sizeof(asn_DEF_InitiateAuthenticationResponse_tags_1)
		/sizeof(asn_DEF_InitiateAuthenticationResponse_tags_1[0]), /* 1 */
	{ &asn_OER_type_InitiateAuthenticationResponse_constr_1, &asn_PER_type_InitiateAuthenticationResponse_constr_1, CHOICE_constraint },
	asn_MBR_InitiateAuthenticationResponse_1,
	2,	/* Elements count */
	&asn_SPC_InitiateAuthenticationResponse_specs_1	/* Additional specs */
};

