
/*******************************************************************************
 *  [FILE NAME]   :      <ComStackTypes.h>                                     *
 *  [AUTHOR]      :      <David S. Alexander>                                  *
 *  [DATE CREATED]:      <Feb 26, 2024>                                        *
 *  [Description] :      < >                                                   *
 *******************************************************************************/

#ifndef PDUR_PBCFG_H_COMSTACKTYPES_H_
#define PDUR_PBCFG_H_COMSTACKTYPES_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "StandardTypes.h"

/*******************************************************************************
 *                             Macro Declarations                              *
 *******************************************************************************/
#define COM_STACK_TYPES_VENDOR_ID             10u
#define COM_STACK_TYPES_MODULE_ID             120u

/* Module Version 1.0.0 */
#define COM_STACK_TYPES_SW_MAJOR_VERSION      1u
#define COM_STACK_TYPES_SW_MINOR_VERSION      0u
#define COM_STACK_TYPES_SW_PATCH_VERSION      0u

/* AUTOSAR Version 4.4.0 */
#define COM_STACK_TYPES_AR_MAJOR_VERSION      4u
#define COM_STACK_TYPES_AR_MINOR_VERSION      4u
#define COM_STACK_TYPES_AR_PATCH_VERSION      0u

/*******************************************************************************
 *                         Data Types Declaration                              *
 *******************************************************************************/

typedef uint16_t        PduIdType;
typedef uint16_t        PduLengthType;

/* Global PDU */
typedef struct
{
    uint32_t           PduLength;
}Pdu_Type;

/* PDU Source */
typedef struct
{
  const PduIdType      SourcePduHandleId;
  Pdu_Type            *SrcPduRef;
}PduRSrcPdu_type;

/* PDU Destination */
typedef struct
{
  const PduIdType      DestPduHandleId;
  Pdu_Type            *DestPduRef;
}PduRDestPdu_type;

/* PDU Routing Path */
typedef struct
{
  PduRSrcPdu_type     *PduRSrcPduRef;
  PduRDestPdu_type    *PduRDestPduRef;
}PduRRoutingPath_type;

typedef enum
{
	TP_DATACONF,
	TP_DATARETRY,
	TP_CONFPENDING
}TpDataStateType;

typedef enum
{
	BUFREQ_E_OK,
	BUFREQ_E_NOT_OK,
	BUFREQ_E_BUSY,
	BUFREQ_E_OVFL
}BufReq_ReturnType;

typedef struct
{
    uint8_t            *SduDataPtr;			/* payload */
    PduLengthType       SduLength;	        /* length of SDU */
} PduInfoType;

typedef struct
{
	TpDataStateType     TpDataState;
	PduLengthType       TxTpDataCnt;
}RetryInfoType;

#endif /* PDUR_PBCFG_H_COMSTACKTYPES_H_ */
