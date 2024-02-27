
/*******************************************************************************
 *  [FILE NAME]   :      <PduR_CanTp.h>                                        *
 *  [AUTHOR]      :      <David S. Alexander>                                  *
 *  [DATE CREATED]:      <27 Feb 2024>                                         *
 *  [Description] :      < >                                                   *
 *******************************************************************************/

#ifndef INC_PDUR_CANTP_H_
#define INC_PDUR_CANTP_H_

/*******************************************************************************
 *                             Macro Declarations                              *
 *******************************************************************************/

/* Service IDs */

#define PDUR_CAN_TP_COPY_RX_DATA_SID                  (uint8_t)(0x44)
#define PDUR_CAN_TP_RX_INDICATION_SID                 (uint8_t)(0x45)
#define PDUR_CAN_TP_START_OF_RECEPTION_SID            (uint8_t)(0x46)
#define PDUR_CAN_TP_COPY_TX_DATA_SID                  (uint8_t)(0x43)
#define PDUR_CAN_TP_TX_CONFIRMATION_SID               (uint8_t)(0x48)

/*******************************************************************************
 *                            Functions Declaration                            *
 *******************************************************************************/
BufReq_ReturnType   PduR_CanTpCopyRxData (PduIdType id, PduInfoType* info, PduLengthType* bufferSizePtr);
void                PduR_CanTpRxIndication (PduIdType id, NotifResultType result);
BufReq_ReturnType   PduR_CanTpStartOfReception (PduIdType id, PduLengthType TpSduLength, PduLengthType* bufferSizePtr);
BufReq_ReturnType   PduR_CanTpCopyTxData (PduIdType id, PduInfoType* info, RetryInfoType* retry, PduLengthType* availableDataPtr);
void                PduR_CanTpTxConfirmation (PduIdType id, NotifResultType result);

#endif /* INC_PDUR_CANTP_H_ */
