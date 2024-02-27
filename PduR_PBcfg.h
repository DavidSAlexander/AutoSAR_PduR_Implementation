
/*******************************************************************************
 *  [FILE NAME]   :      <PduR_PBcfg.h>                                        *
 *  [AUTHOR]      :      <David S. Alexander>                                  *
 *  [DATE CREATED]:      <26 Feb 2024>                                         *
 *  [Description] :      < >                                                   *
 *******************************************************************************/
#ifndef INC_PDUR_PBCFG_H_
#define INC_PDUR_PBCFG_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "StandardTypes.h"
#include "PduR.h"
#include "ComStackTypes.h"


/*******************************************************************************
 *                             Macro Declarations                              *
 *******************************************************************************/
#define PDUR_VERSION_INFO_API                   STD_ON

#define PDUR_PDU_ID_COM_TX_CANIF_MESSAGE_0      0
#define PDUR_PDU_ID_CANIF_RX_COM_MESSAGE_1      1
#define TX_PDU_CNT                              1
#define RX_PDU_CNT                              1

/*******************************************************************************
 *                            External Variables                               *
 *******************************************************************************/
extern PduR_PBConfigType  PBPduRConfig;
extern const uint32_t     Tx_Pdu_Ids[TX_PDU_CNT];
extern const uint32_t     Rx_Pdu_Ids[RX_PDU_CNT];


#endif /* INC_PDUR_PBCFG_H_ */
