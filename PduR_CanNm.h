
/*******************************************************************************
 *  [FILE NAME]   :      <PduR_CanCanNm.h>                                     *
 *  [AUTHOR]      :      <David S. Alexander>                                  *
 *  [DATE CREATED]:      <27 Feb 2024>                                         *
 *  [Description] :      < >                                                   *
 *******************************************************************************/
#ifndef INC_PDUR_CANNM_H_
#define INC_PDUR_CANNM_H_

/*******************************************************************************
 *                             Macro Declarations                              *
 *******************************************************************************/

/* Service IDs */
#define PDUR_CAN_NM_RX_INDICATION_SID                 (uint8_t)(0x45)
#define PDUR_CAN_NM_TRIGGER_TRANSMIT_SID              (uint8_t)(0x41)
#define PDUR_CAN_NM_TX_CONFIRMATION_SID               (uint8_t)(0x48)

/*******************************************************************************
 *                            Functions Declaration                            *
 *******************************************************************************/
void                PduR_CanNmRxIndication (PduIdType id, NotifResultType result);
Std_ReturnType      PduR_CanNmTriggerTransmit (PduIdType pduId, PduInfoType* pduInfoPtr);
void                PduR_CanNmTxConfirmation (PduIdType id, NotifResultType result);

#endif /* INC_PDUR_CANNM_H_ */
