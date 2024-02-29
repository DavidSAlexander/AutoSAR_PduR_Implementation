
/*******************************************************************************
 *  [FILE NAME]   :      <PduR_PBcfg.c>                                        *
 *  [AUTHOR]      :      <David S. Alexander>                                  *
 *  [DATE CREATED]:      <26 Feb 2024>                                         *
 *  [Description] :      < >                                                   *
 *******************************************************************************/


/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "PduR_PBcfg.h"
#include "PduR.h"
#include "StandardTypes.h"


/*******************************************************************************
 *                                Variables                                    *
 *******************************************************************************/

PduInfoType PduInfoSrc =
{
	.SduLength = 8
};

PduInfoType PduInfoDest =
{
	.SduLength = 8
};

PduRSrcPdu_type PduRSrcPdu_Com_To_CanIf =
{
	.PduRSourcePduHandleId = 20,
	.PduRSrcPduUpTxConf    = TRUE,
	.PduRSrcPduRef         = &PduInfoSrc
};

PduRDestPdu_type PduRDestPdu_Com_To_CanIf =
{
	.PduRDestPduDataProvision     = PDUR_DIRECT,
	.PduRDestPduHandleId          = 3,
	.PduRTransmissionConfirmation = TRUE,
	.PduRDestPduRef               = &PduInfoDest
};

PduRSrcPdu_type PduRSrcPdu_CanIf_To_Com =
{
	.PduRSourcePduHandleId        = 2,
	.PduRSrcPduUpTxConf           = TRUE,
	.PduRSrcPduRef                = &PduInfoSrc
};

PduRDestPdu_type PduRDestPdu_CanIf_To_Com =
{
	.PduRDestPduDataProvision     = PDUR_DIRECT,
	.PduRDestPduHandleId          = 10,
	.PduRTransmissionConfirmation = TRUE,
	.PduRDestPduRef               = &PduInfoDest,
	.PduR_Module                  = PDUR_COM
};

PduRRoutingPath_type PDURRoutingPath[] =
{
	{
		/* TRANSMISSION FROM COM TO CANIF */
		.PduRSrcPduRef   = &PduRSrcPdu_Com_To_CanIf,
		.PduRDestPduRRef = &PduRDestPdu_Com_To_CanIf
	},
	{
		/* RECEPTION FROM CANIF TO COM */
		.PduRSrcPduRef   = &PduRSrcPdu_CanIf_To_Com,
		.PduRDestPduRRef = &PduRDestPdu_CanIf_To_Com
	}
};

const PduR_PBConfigType PBPduRConfig =
{
	.PduR.PduRRoutingPaths.PduRConfigurationId   = 0,
	.PduR.PduRRoutingPaths.PduRMaxRoutingPathCnt = sizeof(PDURRoutingPath)/sizeof(PDURRoutingPath[0]),
	.PduR.PduRRoutingPaths.PduRRoutingPath       = PDURRoutingPath,
};
