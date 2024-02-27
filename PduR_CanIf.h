
/*******************************************************************************
 *  [FILE NAME]   :      <PduR_CanIf.h>                                        *
 *  [AUTHOR]      :      <David S. Alexander>                                  *
 *  [DATE CREATED]:      <27 Feb 2024>                                         *
 *  [Description] :      < >                                                   *
 *******************************************************************************/
#ifndef INC_PDUR_CANIF_H_
#define INC_PDUR_CANIF_H_

/*******************************************************************************
 *                             Macro Declarations                              *
 *******************************************************************************/

/* Service IDs */
#define PDUR_CAN_IF_RX_INDICATION_SID                 (uint8_t)(0x42)
#define PDUR_CAN_IF_TX_CONFIRMATION_SID               (uint8_t)(0x40)
#define PDUR_CAN_IF_TRIGGER_TRANSMIT_SID              (uint8_t)(0x41)


/*******************************************************************************
 *                            Functions Declaration                            *
 *******************************************************************************/
void              PduR_CanIfRxIndication (PduIdType RxPduId, const PduInfoType* PduInfoPtr);
void              PduR_CanIfTxConfirmation (PduIdType TxPduId, Std_ReturnType result);
Std_ReturnType    PduR_CanIfTriggerTransmit (PduIdType TxPduId, PduInfoType* PduInfoPtr);

#endif /* INC_PDUR_CANIF_H_ */
