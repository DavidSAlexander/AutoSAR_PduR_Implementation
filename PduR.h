
/*******************************************************************************
 *  [FILE NAME]   :      <PduR.h>                                              *
 *  [AUTHOR]      :      <David S. Alexander>                                  *
 *  [DATE CREATED]:      <Feb 26, 2024>                                        *
 *  [Description] :      < >                                                   *
 *******************************************************************************/
#ifndef PDUR_PBCFG_H_PDUR_H_
#define PDUR_PBCFG_H_PDUR_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "Det.h"
#include "ComStackTypes.h"
#include "PduR_PBcfg.h"

/*******************************************************************************
 *                             Macro Declarations                              *
 *******************************************************************************/

#define PDUR_VENDOR_ID                            10u
#define PDUR_MODULE_ID                            120u
#define PDUR_INSTANCE_ID	                      0u

/* Module Version 1.0.0 */
#define PDUR_SW_MAJOR_VERSION                     1u
#define PDUR_SW_MINOR_VERSION                     0u
#define PDUR_SW_PATCH_VERSION                     0u

/* AUTOSAR Version 4.4.0 */
#define PDUR_AR_MAJOR_VERSION                     4u
#define PDUR_AR_MINOR_VERSION                     4u
#define PDUR_AR_PATCH_VERSION                     0u


/* Development Errors Ids */
#define PDUR_E_INIT_FAILED                        (uint8_t)(0x00)
#define PDUR_E_UNINIT                             (uint8_t)(0x01)
#define PDUR_E_PDU_ID_INVALID                     (uint8_t)(0x02)
#define PDUR_E_ROUTING_PATH_GROUP_ID_INVALID      (uint8_t)(0x08)
#define PDUR_E_PARAM_POINTER                      (uint8_t)(0x09)

/* Runtime Errors Ids */
#define PDUR_E_TP_TX_REQ_REJECTED                 (uint8_t)(0x03)
#define PDUR_E_PDU_INSTANCES_LOST                 (uint8_t)(0x0A)

/* Service IDs */
#define PDUR_INIT_SID                             (uint8_t)(0xF0)
#define PDUR_GET_VERSION_INFO_SID                 (uint8_t)(0xF1)
#define PDUR_GET_CONFIGURATION_ID_SID             (uint8_t)(0xF2)
#define PDUR_ENABLE_ROUTING_SID                   (uint8_t)(0xF3)
#define PDUR_DISABLE_ROUTING_SID                  (uint8_t)(0xF4)

#if ((DET_AR_MAJOR_VERSION != PDUR_AR_MAJOR_VERSION) || (DET_AR_MINOR_VERSION != PDUR_AR_MINOR_VERSION) || (DET_AR_PATCH_VERSION != PDUR_AR_PATCH_VERSION))
#error "The AUTOSAR version of Det.h and PduR.h are different!"
#endif

#if ((DET_SW_MAJOR_VERSION != PDUR_SW_MAJOR_VERSION) || (DET_SW_MINOR_VERSION != PDUR_SW_MINOR_VERSION) || (DET_SW_PATCH_VERSION != PDUR_SW_PATCH_VERSION))
#error "The Software version of Det.h and StandardTypes.h are different!"
#endif

#if ((COM_STACK_TYPES_AR_MAJOR_VERSION != PDUR_AR_MAJOR_VERSION) || (COM_STACK_TYPES_AR_MINOR_VERSION != PDUR_AR_MINOR_VERSION) || (COM_STACK_TYPES_AR_PATCH_VERSION != PDUR_AR_PATCH_VERSION))
#error "The AUTOSAR version of ComStackTypes.h and PduR.h are different!"
#endif

#if ((COM_STACK_TYPES_SW_MAJOR_VERSION != PDUR_SW_MAJOR_VERSION) || (COM_STACK_TYPES_SW_MINOR_VERSION != PDUR_SW_MINOR_VERSION) || (COM_STACK_TYPES_SW_PATCH_VERSION != PDUR_SW_PATCH_VERSION))
#error "The Software version of ComStackTypes.h and StandardTypes.h are different!"
#endif

/*******************************************************************************
 *                          Data Types Declaration                             *
 *******************************************************************************/

typedef enum
{
    PDUR_UNINIT,     /* PDU Router is uninitialized. */
    PDUR_ONLINE      /* PDU Router initialized successfully. */
} PduR_StateType;

typedef enum
{
	PDUR_DIRECT,
	PDUR_TRIGGERTRANSMIT
}PduRDestPduDataProvision_Type;

typedef uint16_t     PduR_PBConfigIdType;
typedef uint16_t     PduR_RoutingPathGroupIdType;

typedef struct
{
	boolean                      PduRIsEnabledAtInit;
	PduR_RoutingPathGroupIdType  PduRRoutingPathGroupId;

}PduRRoutingPathGroup_type;

/* PDU Source */
typedef struct
{
  uint32_t             PduRSourcePduBlockSize;
  const PduIdType      PduRSourcePduHandleId;
  boolean              PduRSrcPduUpTxConf;
  PduInfoType         *PduRSrcPduRef;
}PduRSrcPdu_type;

/* PDU Destination */
typedef struct
{
  PduRDestPduDataProvision_Type PduRDestPduDataProvision;
  const PduIdType               PduRDestPduHandleId;
  boolean                       PduRTransmissionConfirmation;
  PduInfoType                  *PduRDestPduRef;
  PduR_ModuleType               PduR_Module;
}PduRDestPdu_type;

typedef struct
{
    uint32_t                    PduRPduMaxLength;
    uint8_t                    *DataPtr;
}PduRTxBuffer_type;

/* PDU Routing Path */
typedef struct
{
  uint8_t                       PduRQueueDepth;
  uint16_t                      PduRTpThreshold;
  PduRTxBuffer_type            *PduRDestTxBufferRef;
  PduRRoutingPathGroup_type    *PduRRoutingPathGroupRef;
  PduRDestPdu_type             *PduRDestPduRRef;
  PduRSrcPdu_type              *PduRSrcPduRef;
}PduRRoutingPath_type;

typedef struct
{
  PduRRoutingPath_type          PduRRoutingPath;
}PduRRoutingTable_type;

typedef struct
{
	PduR_PBConfigIdType         PduRConfigurationId;
	uint16_t                    PduRMaxRoutingPathCnt;
	uint16_t                    PduRMaxRoutingPathGroupCnt;
	PduRDestPdu_type           *PduRDestPdu;
	PduRRoutingPath_type       *PduRRoutingPath;
	PduRRoutingPathGroup_type  *PduRRoutingPathGroup;
	PduRSrcPdu_type            *PduRSrcPdu;
	PduRTxBuffer_type          *PduRTxBuffer;
}PduRRoutingPaths_type;

typedef struct
{
	boolean                     PduRCancelReceive;
	boolean                     PduRCancelTransmit;
	boolean                     PduRCommunicationInterface;
	boolean                     PduRLowerModule;
	boolean                     PduRRetransmission;
	boolean                     PduRTransportProtocol;
	boolean                     PduRTriggertransmit;
	boolean                     PduRTxConfirmation;
	boolean                     PduRUpperModule;
	boolean                     PduRUseTag;
	PduR_ModuleType            *PduRBswModuleRef;
}PduRBswModules_type;

typedef struct
{
	boolean                     PduRDevErrorDetect;
	boolean                     PduRMetaDataSupport;
	boolean                     PduRZeroCostOperation;
}PduRGeneral_type;

typedef struct
{
	PduRBswModules_type         PduRBswModules;
	PduRGeneral_type            PduRGeneral;
	PduRRoutingPaths_type       PduRRoutingPaths;
}PduR_type;
/* PDUR Configuration */
typedef struct
{
    PduR_type                   PduR;
}PduR_PBConfigType;

/*******************************************************************************
 *                            External Variables                               *
 *******************************************************************************/
extern PduR_StateType              PduRState;
extern const PduR_PBConfigType     PBPduRConfig;

/*******************************************************************************
 *                           Functions Declaration                             *
 *******************************************************************************/
void                 PduR_Init (const PduR_PBConfigType* ConfigPtr);
PduR_PBConfigIdType  PduR_GetConfigurationId (void);
void                 PduR_EnableRouting (PduR_RoutingPathGroupIdType id);
void                 PduR_DisableRouting (PduR_RoutingPathGroupIdType id, boolean initialize);

#if (PDUR_VERSION_INFO_API == STD_ON)
void                 PduR_GetVersionInfo (Std_VersionInfoType* versionInfo);
#endif

#endif /* PDUR_PBCFG_H_PDUR_H_ */
