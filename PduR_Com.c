
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
 *                           Functions Declaration                             *
 *******************************************************************************/

Std_ReturnType PduR_ComTransmit (PduIdType TxPduId, const PduInfoType* PduInfoPtr)
{
	Std_ReturnType ret = E_OK;
    if( PDUR_UNINIT == PduRState )
    {
    	Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_COM_TRANSMIT_SID, PDUR_E_UNINIT);
    }
    else if( PduInfoPtr == NULL_PTR )
    {
    	Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_COM_TRANSMIT_SID, PDUR_E_PARAM_POINTER);
    }
    else
	{

	}
    return ret;
}
