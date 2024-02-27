
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
typedef uint16_t     PduR_PBConfigIdType;
typedef uint16_t     PduR_RoutingPathGroupIdType;

typedef enum
{
    PDUR_UNINIT,     /* PDU Router is uninitialized. */
    PDUR_ONLINE      /* PDU Router initialized successfully. */
} PduR_StateType;

typedef struct
{
    uint32_t    BufSize;
    uint8_t    *DataPtr;
}PduRTxBuffer_type;

/* PDUR Configuration */
typedef struct
{
	PduR_RoutingPathGroupIdType PduRRoutingPathGroup;
    PduR_PBConfigIdType         PduRConfigurationId;

    /* Maximum number of routing paths in all tables */
    const uint16_t              PduRMaxRoutingPathCnt;

    PduR_RoutingPathGroupIdType PduRMaxRoutingPathGroupCnt;
    PduRTxBuffer_type           PduRTxBuffer;
    /* Array of pointers to the routing paths and routing table */
    PduRRoutingPath_type      **RoutingPaths;
}PduR_PBConfigType;

/*******************************************************************************
 *                            External Variables                               *
 *******************************************************************************/
extern const PduR_PBConfigType    *PduRConfig;
extern PduR_StateType              PduRState;

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
