
/*******************************************************************************
 *  [FILE NAME]   :      <PduR_Com.c>                                          *
 *  [AUTHOR]      :      <David S. Alexander>                                  *
 *  [DATE CREATED]:      <26 Feb 2024>                                         *
 *  [Description] :      < >                                                   *
 *******************************************************************************/

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "PduR.h"
#include "PduR_Com.h"

/*******************************************************************************
 *                                Variables                                    *
 *******************************************************************************/


/*******************************************************************************
 *                           Functions Implementation                          *
 *******************************************************************************/

/**
 * @brief Transmits a PDU (Protocol Data Unit) from the upper layer to a destination module.
 *
 * This function routes a PDU identified by TxPduId from the upper layer to its destination module.
 * The PDU data is provided through the PduInfoPtr parameter.
 *
 * @param TxPduId The ID of the PDU to be transmitted.
 * @param PduInfoPtr Pointer to a structure containing the PDU data and its length.
 * @return Std_ReturnType E_OK if the PDU transmission is successful, E_NOT_OK otherwise.
 */
Std_ReturnType PduR_ComTransmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr)
{
    /* Initialize return value to indicate failure by default */
    Std_ReturnType ret = E_NOT_OK;

    /* Check if the PDU Router module is initialized */
    if (PDUR_UNINIT == PduRState)
    {
        /* Report error if PDU Router module is not initialized */
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_COM_TRANSMIT_SID, PDUR_E_UNINIT);
#endif
        /* Return error */
        ret = E_NOT_OK;
    }
    /* Check if PduInfoPtr is NULL */
    else if (PduInfoPtr == NULL_PTR)
    {
        /* Report error if PduInfoPtr is NULL */
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_COM_TRANSMIT_SID, PDUR_E_PARAM_POINTER);
#endif
        /* Return error */
        ret = E_NOT_OK;
    }
    else
    {
        /* Iterate through each routing path to find the matching TxPduId */
        for (uint8_t PathsCounter = 0; PathsCounter < PBPduRConfig.PduRRoutingPaths.PduRMaxRoutingPathCnt; PathsCounter++)
        {
            /* Get the current routing path */
            const PduRRoutingPath_type* RoutingPath = &PBPduRConfig.PduRRoutingPaths.PduRRoutingPath[PathsCounter];

            /* Check if the current routing path matches the TxPduId */
            if (RoutingPath->PduRSrcPduRef->PduRSourcePduHandleId == TxPduId)
            {
                /* Check the data provision type for the destination PDU */
                if (RoutingPath->PduRDestPduRRef->PduRDestPduDataProvision == PDUR_DIRECT)
                {
                    /* If data provision is direct, transmit the PDU directly */

               /* 	switch (RoutingPath->PduRDestPduRRef->PduR_Module)
                	{
                	   case PDUR_CAN_IF:
                	        ret = CanIf_Transmit(RoutingPath->PduRDestPduRRef->PduRDestPduHandleId, PduInfoPtr);
                	        break;
                	   case PDUR_LIN_IF:
                	        ret = LinIf_Transmit(RoutingPath->PduRDestPduRRef->PduRDestPduHandleId, PduInfoPtr);
                	        break;
                   	   case PDUR_FR_IF:
                   	        ret = FrIf_Transmit(RoutingPath->PduRDestPduRRef->PduRDestPduHandleId, PduInfoPtr);
                   	        break;
                   	   case PDUR_FR_NM:
                   	        ret = LinIf_Transmit(RoutingPath->PduRDestPduRRef->PduRDestPduHandleId, PduInfoPtr);
                   	       break;
                   	   default:
                   		   break;
                	}     */
                }
                else if (RoutingPath->PduRDestPduRRef->PduRDestPduDataProvision == PDUR_TRIGGERTRANSMIT)
                {
                    /* If data provision involves triggered transmission, trigger the transmission */

                    /* switch (RoutingPath->PduRDestPduRRef->PduR_Module)
                       {
                     	  case PDUR_CAN_IF:
                     	       ret = CanIf_TriggerTransmit(RoutingPath->PduRDestPduRRef->PduRDestPduHandleId, PduInfoPtr);
                     	       break;
                     	  case PDUR_LIN_IF:
                     	       ret = LinIf_TriggerTransmit(RoutingPath->PduRDestPduRRef->PduRDestPduHandleId, PduInfoPtr);
                     	       break;
                          case PDUR_FR_IF:
                               ret = FrIf_TriggerTransmit(RoutingPath->PduRDestPduRRef->PduRDestPduHandleId, PduInfoPtr);
                               break;
                          case PDUR_FR_NM:
                               ret = LinIf_TriggerTransmit(RoutingPath->PduRDestPduRRef->PduRDestPduHandleId, PduInfoPtr);
                               break;
                          default:
                               break;
                     	}     */
                }
                else
                {
                    /* Unsupported data provision type, break the loop */
                    break;
                }
                /* Break the loop after processing the matching routing path */
                break;
            }
        }
    }

    /* Return the transmission result */
    return ret;
}

