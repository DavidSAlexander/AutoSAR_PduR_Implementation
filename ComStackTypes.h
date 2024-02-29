
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

typedef uint16_t       PduIdType;
typedef uint32_t       PduLengthType;
typedef uint8_t        PduPayloadType;

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

typedef enum
{
	PDUR_DCM,
	PDUR_COM,
	PDUR_CAN_IF,
	PDUR_CAN_TP,
	PDUR_CAN_NM,
	PDUR_LIN_IF,
	PDUR_LIN_TP,
	PDUR_LIN_NM,
	PDUR_FR_IF,
	PDUR_FR_TP,
	PDUR_FR_NM,

}PduR_ModuleType;

typedef struct
{
	PduIdType           PduId;
	PduPayloadType     *SduDataPtr;	        /* payload */
        PduLengthType       SduLength;	        /* length of SDU */
} PduInfoType;

typedef struct
{
	TpDataStateType     TpDataState;
	PduLengthType       TxTpDataCnt;
}RetryInfoType;

#endif /* PDUR_PBCFG_H_COMSTACKTYPES_H_ */
