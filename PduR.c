
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

/*******************************************************************************
 *                                Variables                                    *
 *******************************************************************************/

/* PDUR Initial State */
PduR_StateType PduRState = PDUR_UNINIT;

/* Global PDUR coniguration pointer */
const PduR_PBConfigType* PduRConfig;


/*******************************************************************************
 *                           Functions Declaration                             *
 *******************************************************************************/
void PduR_Init (const PduR_PBConfigType* ConfigPtr)
{
	if (ConfigPtr == NULL_PTR)
	{
		Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_INIT_SID, PDUR_E_INIT_FAILED);
	}
	else if (PduRState == PDUR_UNINIT)
	{
		PduRState = PDUR_ONLINE;
	    PduRConfig = ConfigPtr;
	}
}

PduR_PBConfigIdType PduR_GetConfigurationId (void)
{
    if( PDUR_UNINIT == PduRState )
    {
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_GET_CONFIGURATION_ID_SID, PDUR_E_UNINIT);
    }
    return PduRConfig->PduRConfigurationId;
}

void PduR_EnableRouting (PduR_RoutingPathGroupIdType id)
{
    if( PDUR_UNINIT == PduRState )
    {
    	Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_ENABLE_ROUTING_SID, PDUR_E_UNINIT);
    }
    else
	{
    	if(id < PduRConfig->PduRRoutingPathGroup && PduRConfig->PduRMaxRoutingPathCnt > 0)
    	{

    	}
    	else
    	{
    		Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_ENABLE_ROUTING_SID, PDUR_E_PDU_ID_INVALID);
    	}
	}
}
#if (PDUR_VERSION_INFO_API == STD_ON)
void PduR_GetVersionInfo (Std_VersionInfoType* versionInfo)
{
	if (ConfigPtr == NULL_PTR)
	{
		Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_GET_VERSION_INFO_SID, PDUR_E_PARAM_POINTER);
	}
	else
	{
		versionInfo->ModuleID         = MODULE_ID_PDUR;
		versionInfo->VendorID         = PDUR_VENDOR_ID;
	    versionInfo->SW_Major_Version = PDUR_SW_MAJOR_VERSION;
	    versionInfo->SW_Minor_Version = PDUR_SW_MINOR_VERSION;
	    versionInfo->SW_Patch_Version = PDUR_SW_PATCH_VERSION;
	}
}
#endif
