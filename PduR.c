
/*******************************************************************************
 *  [FILE NAME]   :      <PduR.c>                                              *
 *  [AUTHOR]      :      <David S. Alexander>                                  *
 *  [DATE CREATED]:      <26 Feb 2024>                                         *
 *  [Description] :      < >                                                   *
 *******************************************************************************/

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "PduR.h"
#include "PduR_PBcfg.h"

/*******************************************************************************
 *                                Variables                                    *
 *******************************************************************************/

/* PDUR Initial State */
PduR_StateType PduRState = PDUR_UNINIT;

/* Global PDUR coniguration pointer */
const PduR_PBConfigType* PduRConfig;


/*******************************************************************************
 *                         Functions Implementation                            *
 *******************************************************************************/
void PduR_Init (const PduR_PBConfigType* ConfigPtr)
{
	if (ConfigPtr == NULL_PTR)
	{
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
		Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_INIT_SID, PDUR_E_INIT_FAILED);
#endif
		return;
	}
	else if (PduRState == PDUR_UNINIT)
	{
		PduRConfig = ConfigPtr;
		PduRState = PDUR_ONLINE;
	}
}

PduR_PBConfigIdType PduR_GetConfigurationId (void)
{
    if( PDUR_UNINIT == PduRState )
    {
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_GET_CONFIGURATION_ID_SID, PDUR_E_UNINIT);
#endif
        return 0;
    }
    return PduRConfig->PduRRoutingPaths.PduRConfigurationId;
}

void PduR_EnableRouting (PduR_RoutingPathGroupIdType id)
{
    if( PDUR_UNINIT == PduRState )
    {
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    	Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_ENABLE_ROUTING_SID, PDUR_E_UNINIT);
#endif
    	return;
    }
    else
	{
    	if(id < PduRConfig->PduRRoutingPaths.PduRMaxRoutingPathCnt)
    	{

    	}
    	else
    	{
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    		Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_ENABLE_ROUTING_SID, PDUR_E_PDU_ID_INVALID);
#endif
    	}
	}
}
#if (PDUR_VERSION_INFO_API == STD_ON)
void PduR_GetVersionInfo (Std_VersionInfoType* versionInfo)
{
	if (versionInfo == NULL_PTR)
	{
		Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_GET_VERSION_INFO_SID, PDUR_E_PARAM_POINTER);
	}
	else
	{
	    versionInfo->ModuleID         = PDUR_MODULE_ID;
	    versionInfo->VendorID         = PDUR_VENDOR_ID;
	    versionInfo->SW_Major_Version = PDUR_SW_MAJOR_VERSION;
	    versionInfo->SW_Minor_Version = PDUR_SW_MINOR_VERSION;
	    versionInfo->SW_Patch_Version = PDUR_SW_PATCH_VERSION;
	}
}
#endif
