
/*******************************************************************************
 *  [FILE NAME]   :      <StandardTypes.h>                                     *
 *  [AUTHOR]      :      <David S. Alexander>                                  *
 *  [DATE CREATED]:      <Feb 26, 2024>                                        *
 *  [Description] :      < >                                                   *
 *******************************************************************************/
#ifndef PDUR_PBCFG_H_STANDARDTYPES_H_
#define PDUR_PBCFG_H_STANDARDTYPES_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "main.h"

/*******************************************************************************
 *                             Macro Declarations                              *
 *******************************************************************************/

#define STD_TYPES_VENDOR_ID             10u
#define STD_TYPES_MODULE_ID             120u

/* Module Version 1.0.0 */
#define STD_TYPES_SW_MAJOR_VERSION      1u
#define STD_TYPES_SW_MINOR_VERSION      0u
#define STD_TYPES_SW_PATCH_VERSION      0u

/* AUTOSAR Version 4.4.0 */
#define STD_TYPES_AR_MAJOR_VERSION      4u
#define STD_TYPES_AR_MINOR_VERSION      4u
#define STD_TYPES_AR_PATCH_VERSION      0u

#define STD_HIGH                        1u
#define STD_LOW                         0u
#define STD_ACTIVE                      1u
#define STD_IDLE                        0u
#define STD_ON                          1u
#define STD_OFF                         0u
#define E_OK                            0u
#define E_NOT_OK                        1u
#define FALSE                           0u
#define TRUE                            1u
#define ZERO_INIT                       0u
#define NULL_PTR                        ((void *)0)

/*******************************************************************************
 *                         Data Types Declaration                              *
 *******************************************************************************/

typedef uint8_t             Std_ReturnType;
typedef uint8_t      		boolean;

typedef struct
{
	uint16_t VendorID;
	uint16_t ModuleID;
	uint8_t  SW_Major_Version;
	uint8_t  SW_Minor_Version;
	uint8_t  SW_Patch_Version;
} Std_VersionInfoType;

#endif /* PDUR_PBCFG_H_STANDARDTYPES_H_ */
