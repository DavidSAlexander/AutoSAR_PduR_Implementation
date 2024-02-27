
/*******************************************************************************
 *  [FILE NAME]   :      <PDUR_Com.h>                                          *
 *  [AUTHOR]      :      <David S. Alexander>                                  *
 *  [DATE CREATED]:      <26 Feb 2024>                                         *
 *  [Description] :      < >                                                   *
 *******************************************************************************/

#ifndef PDUR_PBCFG_H_PDUR_COM_H_
#define PDUR_PBCFG_H_PDUR_COM_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "ComStackTypes.h"
#include "StandardTypes.h"

/*******************************************************************************
 *                             Macro Declarations                              *
 *******************************************************************************/

/* Service IDs */
#define PDUR_COM_TRANSMIT_SID                     (uint8_t)(0x49)
#define PDUR_COM_CANCEL_TRANSMIT_SID              (uint8_t)(0x4A)
#define PDUR_COM_CANCEL_RECEIVE_SID               (uint8_t)(0x4C)
#define PDUR_COM_RX_INDICATION_SID                (uint8_t)(0x42)


/*******************************************************************************
 *                            Functions Declaration                            *
 *******************************************************************************/

Std_ReturnType    PduR_ComTransmit (PduIdType TxPduId, const PduInfoType* PduInfoPtr);
Std_ReturnType    PduR_ComCancelTransmit (PduIdType TxPduId);
Std_ReturnType    PduR_ComCancelReceive (PduIdType RxPduId);
void              PduR_ComRxIndication (PduIdType RxPduId, const PduInfoType* PduInfoPtr);

#endif /* PDUR_PBCFG_H_PDUR_COM_H_ */
