/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "RSPDefinitions"
 * 	found in "../../../asn1/rsp.asn"
 * 	`asn1c -fwide-types -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_InitialiseSecureChannelRequest_H_
#define	_InitialiseSecureChannelRequest_H_


#include "asn_application.h"

/* Including external dependencies */
#include "RemoteOpId.h"
#include "TransactionId.h"
#include "ControlRefTemplate.h"
#include "OCTET_STRING.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* InitialiseSecureChannelRequest */
typedef struct InitialiseSecureChannelRequest {
	RemoteOpId_t	 remoteOpId;
	TransactionId_t	 transactionId;
	ControlRefTemplate_t	 controlRefTemplate;
	OCTET_STRING_t	 smdpOtpk;
	OCTET_STRING_t	 smdpSign;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} InitialiseSecureChannelRequest_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_InitialiseSecureChannelRequest;
extern asn_SEQUENCE_specifics_t asn_SPC_InitialiseSecureChannelRequest_specs_1;
extern asn_TYPE_member_t asn_MBR_InitialiseSecureChannelRequest_1[5];

#ifdef __cplusplus
}
#endif

#endif	/* _InitialiseSecureChannelRequest_H_ */
#include "asn_internal.h"
