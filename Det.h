
/*******************************************************************************
 *  [FILE NAME]   :      <Det.h>                                               *
 *  [AUTHOR]      :      <David S. Alexander>                                  *
 *  [DATE CREATED]:      <Feb 26, 2024>                                        *
 *  [Description] :      <Error detection header file>                         *
 *******************************************************************************/
#ifndef PDUR_PBCFG_H_DET_H_
#define PDUR_PBCFG_H_DET_H_

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "Det_Cfg.h"
#include "StandardTypes.h"

/*******************************************************************************
 *                             Macro Declarations                              *
 *******************************************************************************/
#define DET_VENDOR_ID                       10u

#define DET_MODULE_ID                       17u


#define DET_SW_MAJOR_VERSION                1u
#define DET_SW_MINOR_VERSION                0u
#define DET_SW_PATCH_VERSION                0u

#define DET_AR_MAJOR_VERSION                4u
#define DET_AR_MINOR_VERSION                4u
#define DET_AR_PATCH_VERSION                0u

#if ((DET_AR_MAJOR_VERSION != STD_TYPES_AR_MAJOR_VERSION) || (DET_AR_MINOR_VERSION != STD_TYPES_AR_MINOR_VERSION) || (DET_AR_PATCH_VERSION != STD_TYPES_AR_PATCH_VERSION))
#error "The AUTOSAR version of Det.h and StandardTypes.h are different!"
#endif

#if ((DET_SW_MAJOR_VERSION != STD_TYPES_SW_MAJOR_VERSION) || (DET_SW_MINOR_VERSION != STD_TYPES_SW_MINOR_VERSION) || (DET_SW_PATCH_VERSION != STD_TYPES_SW_PATCH_VERSION))
#error "The Software version of Det.h and StandardTypes.h are different!"
#endif

/*******************************************************************************
 *                         Data Types Declaration                              *
 *******************************************************************************/
typedef struct
{
  uint16_t  ModuleId;
  uint8_t   InstanceId;
  uint8_t   ApiId;
  uint8_t   ErrorId;
} Det_Type;


/*******************************************************************************
 *                            Functions Declaration                            *
 *******************************************************************************/

void Det_ReportError(uint16_t ModuleId, uint8_t InstanceId, uint8_t ApiId, uint8_t ErrorId);

#if (DET_VERSIONINFO_API == STD_ON)
void Det_GetVersionInfo(Std_VersionInfoType* Version);
#endif

#endif /* PDUR_PBCFG_H_DET_H_ */
