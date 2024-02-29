
/*******************************************************************************
 *  [FILE NAME]   :      <Det.c>                                               *
 *  [AUTHOR]      :      <David S. Alexander>                                  *
 *  [DATE CREATED]:      <29 Feb 2024>                                         *
 *  [Description] :      < >                                                   *
 *******************************************************************************/


/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "Det.h"


/*******************************************************************************
 *                         Functions Implementation                            *
 *******************************************************************************/
void Det_ReportError(uint16_t ModuleId, uint8_t InstanceId, uint8_t ApiId, uint8_t ErrorId)
{
	while(1);
}

#if (DET_VERSION_INFO_API == STD_ON)
void Det_GetVersionInfo(Std_VersionInfoType* Version)
{
	if (Version == NULL_PTR)
	{
		Det_ReportError(DET_MODULE_ID, DET_INSTANCE_ID, DET_GET_VERSION_INFO_SID, DET_E_PARAM_POINTER);
	}
	else
	{
		Version->ModuleID         = DET_MODULE_ID;
		Version->VendorID         = DET_VENDOR_ID;
		Version->SW_Major_Version = DET_SW_MAJOR_VERSION;
		Version->SW_Minor_Version = DET_SW_MINOR_VERSION;
		Version->SW_Patch_Version = DET_SW_PATCH_VERSION;
	}
}
#endif
