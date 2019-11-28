/*******************************************************************************
**                                                                            **
**  Copyright (C) AUTOSarZs olc (2019)		                                  **
**                                                                            **
**  All rights reserved.                                                      **
**                                                                            **
**  This document contains proprietary information belonging to AUTOSarZs     **
**  olc . Passing on and copying of this document, and communication          **
**  of its contents is not permitted without prior written authorization.     **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : CanIf_Cfg			                                      **
**                                                                            **
**  VERSION      : 1.0.0                                                      **
**                                                                            **
**  DATE         : 2019-10-20                                                 **
**                                                                            **
**  VARIANT      : Variant PB                                                 **
**                                                                            **
**  PLATFORM     : TIVA C		                                              **
**                                                                            **
**  AUTHOR       : AUTOSarZs-DevTeam	                                      **
**                                                                            **
**  VENDOR       : AUTOSarZs OLC	                                          **
**                                                                            **
**                                                                            **
**  DESCRIPTION  : CAN Interface source file                                  **
**                                                                            **
**  SPECIFICATION(S) : Specification of CAN Inteface, AUTOSAR Release 4.3.1   **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifndef __CANIF_CFG_H__
#define __CANIF_CFG_H__


//*****************************************************************************
//  This parameter defines if the buffer element length shall be fixed to 8
//  Bytes for buffers to which only PDUs < 8 Bytes are assigned.
//  TRUE: Minimum buffer element length is fixed to 8 Bytes. FALSE:
//  Buffer element length depends on the size of the referencing PDUs
//  Default Value: false
//*****************************************************************************
#define CanIfFixedBuffer                		STD_OFF

//*****************************************************************************
//  Selects whether Data Length Check is supported.
//  True: Enabled False: Disabled
//  Default Value: true
//*****************************************************************************
#define CanIfPrivateDataLengthCheck     		STD_ON

//*****************************************************************************
//  Selects the desired software filter mechanism for reception only. Each
//  implemented software filtering method is identified by this enumeration
//  number.
//  Range: 	BINARY Selects Binary Filter method.
//			INDEX Selects Index Filter method.
//			LINEAR Selects Linear Filter method.
//			TABLE Selects Table Filter method.
//	dependency: BasicCAN reception must be enabled by referenced
//	parameter CAN_HANDLE_TYPE of the CAN Driver module via
//	CANIF_HRH_HANDLETYPE_REF for at least one HRH.
//*****************************************************************************
typedef uint8 CanIfPrivateSoftwareFilterType;
#define BINARY	((CanIfPrivateSoftwareFilterType)0x00)
#define INDEX	((CanIfPrivateSoftwareFilterType)0x01)
#define LINEAR	((CanIfPrivateSoftwareFilterType)0x02)
#define TABLE	((CanIfPrivateSoftwareFilterType)0x03)

//*****************************************************************************
//  Defines whether TTCAN is supported.
//  TRUE: TTCAN is supported. FALSE: TTCAN is not supported, only
//  normal CAN communication is possible.
//  Default Value: false
//*****************************************************************************
#define CanIfSupportTTCAN                    	STD_OFF

//*****************************************************************************
//  Switches the development error detection and notification on or off.
//  true: detection and notification is enabled.
//  false: detection and notification is disabled.
//  Default Value: false
//*****************************************************************************
#define CanIfDevErrorDetect                 	STD_OFF

//*****************************************************************************
//  Enable support for dynamic ID handling using L-SDU MetaData.
//  Default Value: false
//*****************************************************************************
#define CanIfMetaDataSupport                	STD_OFF

//*****************************************************************************
//  Configuration parameter to enable/disable dummy API for upper layer
//  modules which allows to request the cancellation of an I-PDU.
//*****************************************************************************
#define CanIfPublicCancelTransmitSupport    	STD_OFF

//*****************************************************************************
//  Defines header files for callback functions which shall be included in
//	case of CDDs. Range of characters is 1.. 32.
//	Type: EcucStringParamDef
//*****************************************************************************
#define CanIfPublicCddHeaderFile    			32

//*****************************************************************************
//	This parameter is used to configure the Can_HwHandleType. The
//	Can_HwHandleType represents the hardware object handles of a CAN
//	hardware unit. For CAN hardware units with more than 255 HW objects
//	the extended range shall be used (UINT16).
//*****************************************************************************
typedef uint16 CanIfPublicHandleTypeEnum;
#define UINT16 	((CanIfPublicHandleTypeEnum)0xFFFF)
#define UINT8	((CanIfPublicHandleTypeEnum)0x0FF)

//*****************************************************************************
//  Selects support of Pretended Network features in CanIf.
//  True: Enabled False: Disabled
//  Default Value: false
//*****************************************************************************
#define CanIfPublicIcomSupport              	STD_OFF

//*****************************************************************************
//  Selects support for multiple CAN Drivers.
//  True: Enabled False: Disabled
//  Default Value: True
//*****************************************************************************
#define CanIfPublicMultipleDrvSupport       	STD_ON

//*****************************************************************************
//  Selects support of Partial Network features in CanIf.
//  True: Enabled False: Disabled
//  Default Value: False
//*****************************************************************************
#define CanIfPublicPnSupport                	STD_OFF

//*****************************************************************************
//  Enables / Disables the API CanIf_ReadRxPduData() for reading
//  received L-SDU data.True: Enabled False: Disabled
//  Default Value: False
//*****************************************************************************
#define CanIfPublicReadRxPduDataApi           	STD_OFF

//*****************************************************************************
//  Enables and disables the API for reading the notification status of
//  receive L-PDU.True: Enabled False: Disabled
//  Default Value: False
//*****************************************************************************
#define CanIfPublicReadRxPduNotifyStatusApi   	STD_OFF

//*****************************************************************************
//  Enables and disables the API for reading the notification status of
//  transmit L-PDUs.True: Enabled False: Disabled
//  Default Value: False
//*****************************************************************************
#define CanIfPublicReadTxPduNotifyStatusApi   	STD_OFF

//*****************************************************************************
//  Enables and disables the API for reconfiguration of the CAN Identifier
//  for each Transmit L-PDU.True: Enabled False: Disabled
//  Default Value: False
//*****************************************************************************
#define CanIfPublicSetDynamicTxIdApi          	STD_OFF

//*****************************************************************************
//  Enables and disables the buffering of transmit L-PDUs (rejected by the
//  CanDrv) within the CAN Interface module.True: Enabled False: Disabled
//  Default Value: False
//*****************************************************************************
#define CanIfPublicTxBuffering                	STD_OFF

//*****************************************************************************
//  Configuration parameter to enable/disable the API to poll for Tx
//  Confirmation state.
//	dependency: CAN State Manager module
//*****************************************************************************
#define CanIfPublicTxConfirmPollingSupport    	STD_OFF

//*****************************************************************************
//  Selects support for wake up validation. True: Enabled False: Disabled
//  Default Value: False
//*****************************************************************************
#define CanIfPublicWakeupCheckValidSupport		STD_OFF

//*****************************************************************************
//  If enabled, only NM messages shall validate a detected wake-up event
//  in CanIf. If disabled, all received messages corresponding to a
//  configured Rx PDU shall validate such a wake-up event. This
//  parameter depends on CanIfPublicWakeupCheckValidSupport and
//  shall only be configurable, if it is enabled.
//	True: Enabled False: Disabled
//	dependency: CanIfPublicWakeupCheckValidSupport
//*****************************************************************************
#if(CanIfPublicWakeupCheckValidSupport==STD_ON)
	#define CanIfPublicWakeupCheckValidByNM		STD_OFF
#endif

//*****************************************************************************
//  Configuration parameter to enable/disable the CanIf_SetBaudrate API
//  to change the baud rate of a CAN Controller. If this parameter is set to
//  true the CanIf_SetBaudrate API shall be supported. Otherwise the API
//  is not supported
//  Default Value: False
//*****************************************************************************
#define CanIfSetBaudrateApi                   	STD_OFF

//*****************************************************************************
//  Enables the CanIf_TriggerTransmit API at Pre-Compile-Time.
//  Therefore, this parameter defines if there shall be support for trigger
//  transmit transmissions. TRUE: Enabled FALSE: Disabled
//  Default Value: True
//*****************************************************************************
#define CanIfTriggerTransmitSupport           	STD_ON

//*****************************************************************************
//	Determines wether TxOffLineActive feature (see SWS_CANIF_00072)
//	is supported by CanIf. True: Enabled False: Disabled
//	Default value: False
//*****************************************************************************
#define CanIfTxOfflineActiveSupport			  	STD_OFF

//*****************************************************************************
//	Enables and disables the API for reading the version information about
//	the CAN Interface.
//	True: Enabled False: Disabled
//	Default value: False
//*****************************************************************************
#define CanIfVersionInfoApi					  	STD_OFF

//*****************************************************************************
//	Enables the CanIf_CheckWakeup API at Pre-Compile-Time.
//	Therefore, this parameter defines if there shall be support for wake-up.
//	True: Enabled False: Disabled
//	Default value: True
//*****************************************************************************
#define CanIfWakeupSupport						STD_ON

//*****************************************************************************
//	Selects the CAN Interface specific configuration setup. This type of the
//	external data structure shall contain the post build initialization data for
//	the CAN Interface for all underlying CAN Drivers.
//	constant to CanIf_ConfigType
//	Type: EcucStringParamDef
//  Length: 1 - 32
//*****************************************************************************
#define CanIfInitCfgSet							(32U)

/* Maximum total size of all Tx buffers. This parameter is needed only in
case of post-build loadable implementation using static memory
allocation.
Range: 0..18446744073709551615 */
#define CanIfMaxBufferSizeValue					(18446744073709551615)

/* Maximum number of Pdus. This parameter is needed only in case of
post-build loadable implementation using static memory allocation.
Range: 0..18446744073709551615 */
#define CanIfMaxRxPduCfgValue					(18446744073709551615)

/* Maximum number of Pdus. This parameter is needed only in case of
post-build loadable implementation using static memory allocation.
Range: 0..18446744073709551615 */
#define CanIfMaxTxPduCfgValue					(18446744073709551615)

/* CAN Identifier of transmit CAN L-PDUs used by the CAN Driver for
CAN L-PDU transmission. Range: 11 Bit For Standard CAN Identifier
... 29 Bit For Extended CAN identifier
The CAN Identifier may be omitted for dynamic transmit L-PDUs. */
#define CanIfTxPduCanId0						(0U)
#define CanIfTxPduCanId1						(1U)

/* Identifier mask which denotes relevant bits in the CAN Identifier. This
parameter may be used to keep parts of the CAN Identifier of dynamic
transmit L-PDUs static. Range: 11 bits for Standard CAN Identifier, 29
bits for Extended CAN Identifier.
Range: 0 .. 536870911 */
#define CanIfTxPduCanIdMask0					(1<<(uint32)0)
#define CanIfTxPduCanIdMask1					(1<<(uint32)1)

/* Type of CAN Identifier of the transmit CAN L-PDU used by the CAN
Driver module for CAN L-PDU transmission. 
Range: 	EXTENDED_CAN CAN 		frame with extended identifier (29 bits)
		EXTENDED_FD_CAN CAN FD 	frame with extended identifier (29 bits)
		STANDARD_CAN CAN 		frame with standard identifier (11 bits)
		STANDARD_FD_CAN CAN FD 	frame with standard identifier (11 bits)*/
typedef uint8 CANIF_TXPDU_CANID_TYPE;
#define EXTENDED_CAN							((CANIF_TXPDU_CANID_TYPE)0x00U)
#define EXTENDED_FD_CAN							((CANIF_TXPDU_CANID_TYPE)0x01U)
#define STANDARD_CAN							((CANIF_TXPDU_CANID_TYPE)0x02U)
#define STANDARD_FD_CAN							((CANIF_TXPDU_CANID_TYPE)0x03U)

/* ECU wide unique, symbolic handle for transmit CAN L-SDU.
Range: 0..max. number of CantTxPduIds. Range: 0 - 4294967295*/
#define CanIfTxPduIdValue						(4294967295U)

/* If CanIfPublicPnFilterSupport is enabled, by this parameter PDUs
could be configured which will pass the CanIfPnFilter.
If there is no CanIfTxPduPnFilterPdu configured per controller,
the corresponding controller applies no CanIfPnFilter.
dependency: This parameter shall only be configurable if CanIfPublicPnSupport equals True. */
#if(CanIfPublicPnSupport==STD_ON)
	#define CANIF_TXPDU_PNFILTER_PDU			STD_OFF
#endif

/* Enables and disables transmit confirmation for each transmit CAN
L-SDU for reading its notification status.
True: Enabled False: Disabled
dependency: CANIF_READTXPDU_NOTIFY_STATUS_API must be enabled.*/
#define CANIF_READTXPDU_NOTIFY_STATUS_API		STD_OFF

/* Enables and disables transmit confirmation for each transmit CAN
L-SDU for reading its notification status.
True: Enabled False: Disabled
dependency: CANIF_READTXPDU_NOTIFY_STATUS_API must be enabled.*/
#if(CANIF_READTXPDU_NOTIFY_STATUS_API==STD_ON)
	#define CANIF_TXPDU_READ_NOTIFYSTATUS		STD_OFF
#endif

/* Determines if or if not CanIf shall use the trigger transmit API for this PDU.
dependency: If CanIfTxPduTriggerTransmit is TRUE then CanIfTxPduUserTxConfirmationUL 
has to be either PDUR or CDD and CanIfTxPduUserTriggerTransmitName has to be specified accordingly */
#define CANIF_TXPDU_TRIGGERTRANSMIT				STD_OFF

/* Enables/disables truncation of PDUs that exceed the configured size. */
#define CANIF_TXPDU_TRUNCATION					STD_ON

/* Defines the type of each transmit CAN L-PDU.
Range:	DYNAMIC 	CAN ID is defined at runtime.
		STATIC 		CAN ID is defined at compile-time. */
typedef uint8 CANIF_TXPDU_TYPE;
#define DYNAMIC									((CANIF_TXPDU_TYPE)0x00U)
#define STATIC									((CANIF_TXPDU_TYPE)0x01U)

/* This parameter defines the upper layer (UL) module to which the confirmation of
the successfully transmitted CANTXPDUID has to be routed via the <User_TxConfirmation>.
This <User_TxConfirmation> has to be invoked when the confirmation of the configured CANTXPDUID
will be received by a Tx confirmation event from the CAN Driver module.
If no upper layer (UL) module is configured, no <User_TxConfirmation> has to be called in case of
a Tx confirmation event of the CANTXPDUID from the CAN Driver module.
Range:	CAN_NM		CAN NM
		CAN_TP 		CAN TP
		CAN_TSYN	Global Time Synchronization over CAN
		CDD 		Complex Driver
		J1939NM 	J1939Nm
		J1939TP 	J1939Tp
		PDUR 		PDU Router
		XCP 		Extended Calibration Protocol 
Note: If CanIfTxPduTriggerTransmit is not specified or FALSE, no upper
layer modules have to be configured for Trigger Transmit. Therefore,
<User_TriggerTransmit>() will not be called and CanIfTxPduUserTxConfirmationUL
as well as CanIfTxPduUserTriggerTransmitName need not to be configured. */
#if(CANIF_TXPDU_TRIGGERTRANSMIT==STD_ON)
	typedef uint8 CANIF_TXPDU_USERTXCONFIRMATION_UL;
	#define CAN_NM								((CANIF_TXPDU_USERTXCONFIRMATION_UL)0x00U)
	#define CAN_TP								((CANIF_TXPDU_USERTXCONFIRMATION_UL)0x01U)
	#define CAN_TSYN							((CANIF_TXPDU_USERTXCONFIRMATION_UL)0x02U)
	#define CDD									((CANIF_TXPDU_USERTXCONFIRMATION_UL)0x03U)
	#define J1939NM								((CANIF_TXPDU_USERTXCONFIRMATION_UL)0x04U)
	#define J1939TP								((CANIF_TXPDU_USERTXCONFIRMATION_UL)0x05U)
	#define PDUR								((CANIF_TXPDU_USERTXCONFIRMATION_UL)0x06U)
	#define XCP									((CANIF_TXPDU_USERTXCONFIRMATION_UL)0x07U)
#endif

/* This parameter defines the name of the <User_TxConfirmation>. This parameter depends
on the parameter CanIfTxPduUserTxConfirmationUL. If CanIfTxPduUserTxConfirmationUL equals
CAN_TP, CAN_NM, PDUR, XCP, CAN_TSYN, J1939NM or J1939TP, the name of the <User_TxConfirmation> is fixed.
If CanIfTxPduUserTxConfirmationUL equals CDD, the name of the <User_TxConfirmation> is selectable.

Note: If transmit confirmations are not necessary or no upper layer modules are configured
for transmit confirmations and thus <User_TxConfirmation>() shall not be called, CanIfTxPduUserTxConfirmationUL
and CanIfTxPduUserTxConfirmationName need not to be configured.

[SWS_CANIF_00890] Configuration of <User_TriggerTransmit>(): If CanIfTxPduUserTxConfirmationUL
is set to PDUR, CanIfTxPduUserTriggerTransmitName must be PduR_CanIfTriggerTransmit.

[SWS_CANIF_00891] Configuration of <User_TriggerTransmit>(): If CanIfTxPduUserTxConfirmationUL
is set to CDD, the name of the API <User_TriggerTransmit>() has to be configured via parameter CanIfTxPduUserTriggerTransmitName. */
#if(CANIF_TXPDU_TRIGGERTRANSMIT==STD_ON)
	#if(CanIfTxPduUserTxConfirmationUL==PDUR)
		#define CanIfTxPduUserTxConfirmationName	PduR_CanIfTxConfirmation
	#else if(CanIfTxPduUserTxConfirmationUL==CAN_NM)
		#define CanIfTxPduUserTxConfirmationName	CanNm_TxConfirmation
	#else if(CanIfTxPduUserTxConfirmationUL==J1939NM)
		#define CanIfTxPduUserTxConfirmationName	J1939Nm_TxConfirmation
	#else if(CanIfTxPduUserTxConfirmationUL==J1939TP)
		#define CanIfTxPduUserTxConfirmationName	J1939Tp_TxConfirmation
	#else if(CanIfTxPduUserTxConfirmationUL==CAN_TP)
		#define CanIfTxPduUserTxConfirmationName	CanTp_TxConfirmation
	#else if(CanIfTxPduUserTxConfirmationUL==XCP)
		#define CanIfTxPduUserTxConfirmationName	Xcp_CanIfTxConfirmation
	#else if(CanIfTxPduUserTxConfirmationUL==CAN_TSYN)
		#define CanIfTxPduUserTxConfirmationName	CanTSyn_CanIfTxConfirmation

	#else if(CanIfTxPduUserTxConfirmationUL==CDD)
		#define CanIfTxPduUserTxConfirmationName	CDD_CanIfTxConfirmation /* Selectable */
	#endif	
#endif


/* CAN Identifier of Receive CAN L-PDUs used by the CAN Interface.
Exa: Software Filtering. This parameter is used if exactly one Can
Identifier is assigned to the Pdu. If a range is assigned then the
CanIfRxPduCanIdRange parameter shall be used.
Range: 11 Bit For Standard CAN Identifier ... 29 Bit For Extended CAN identifier */
#define CanIfRxPduCanId0						(0U)
#define CanIfRxPduCanId1						(1U)

/* Identifier mask which denotes relevant bits in the CAN Identifier. This
parameter defines a CAN Identifier range in an alternative way to
CanIfRxPduCanIdRange. It identifies the bits of the configured CAN
Identifier that must match the received CAN Identifier. Range: 11 bits
for Standard CAN Identifier, 29 bits for Extended CAN Identifier. */
#define CanIfRxPduCanIdMask0					(1<<(uint32)0)
#define CanIfRxPduCanIdMask1					(1<<(uint32)1)

/* CAN Identifier of receive CAN L-PDUs used by the CAN Driver for
CAN L-PDU reception.
Range: 	EXTENDED_CAN 			CAN 2.0 or CAN FD frame with extended identifier (29 bits)
		EXTENDED_FD_CAN 		CAN FD frame with extended identifier (29 bits)
		EXTENDED_NO_FD_CAN		CAN 2.0 frame with extended identifier (29 bits)
		STANDARD_CAN 			CAN 2.0 or CAN FD frame with standard identifier (11 bits)
		STANDARD_FD_CAN 		CAN FD frame with standard identifier (11 bits)
		STANDARD_NO_FD_CAN 		CAN 2.0 frame with standard identifier (11 bits)
dependency: If CanIfRxPduDataLength > 8 then CanIfRxPduCanIdType must not be STANDARD_NO_FD_CAN or EXTENDED_NO_FD_CAN */
typedef uint8 CANIF_RXPDU_CANID_TYPE;
#define EXTENDED_CAN							((CANIF_RXPDU_CANID_TYPE)0x00U)
#define EXTENDED_FD_CAN							((CANIF_RXPDU_CANID_TYPE)0x01U)
#if(CanIfRxPduDataLength <= 8)
	#define EXTENDED_NO_FD_CAN					((CANIF_RXPDU_CANID_TYPE)0x02U)
#endif
#define STANDARD_CAN							((CANIF_RXPDU_CANID_TYPE)0x03U)
#define STANDARD_FD_CAN							((CANIF_RXPDU_CANID_TYPE)0x04U)
#if(CanIfRxPduDataLength <= 8)
	#define STANDARD_NO_FD_CAN					((CANIF_RXPDU_CANID_TYPE)0x05U)
#endif

/* Data length of the received CAN L-PDUs used by the CAN Interface. This information is
used for Data Length Check. Additionally it might specify the valid bits in case of the 
discrete DLC for CAN FD L-PDUs > 8 bytes. The data area size of a CAN L-PDU can have a range from 0 to 64 bytes. */
#define CANIF_RXPDU_DATALENGTH					(8U)

/* ECU wide unique, symbolic handle for receive CAN L-SDU. It shall
fulfill ANSI/AUTOSAR definitions for constant defines. Range: 0..max. number of defined CanRxPduIds
Range: 0 - 4294967295 */
#define CanIfRxPduIdValue						(4294967295U)

/* Enables and disables the Rx buffering for reading of received L-SDU
data. True: Enabled False: Disabled
dependency: CANIF_CANPDUID_READDATA_API must be enabled */
#define CANIF_CANPDUID_READDATA_API				(STD_ON)

/* Enables and disables the Rx buffering for reading of received L-SDU
data. True: Enabled False: Disabled
dependency: CANIF_CANPDUID_READDATA_API must be enabled */
#if(CANIF_CANPDUID_READDATA_API==STD_ON)
	#define CANIF_RXPDU_READDATA				(STD_OFF)
#endif

/* Enables and disables receive indication for each receive CAN L-SDU
for reading its notification status.
True: Enabled False: Disabled
dependency: CANIF_READRXPDU_NOTIFY_STATUS_API must be enabled. */
#define CANIF_READRXPDU_NOTIFY_STATUS_API		STD_OFF

/* Enables and disables receive indication for each receive CAN L-SDU
for reading its notification status.
True: Enabled False: Disabled
dependency: CANIF_READRXPDU_NOTIFY_STATUS_API must be enabled. */
#if(CanIfPublicReadRxPduNotifyStatusApi==STD_ON)
	#define CANIF_RXPDU_READ_NOTIFYSTATUS		STD_OFF
#endif

/* This parameter defines the upper layer (UL) module to which the indication of
the successfully received CANRXPDUID has to be routed via <User_RxIndication>.
This <User_RxIndication> has to be invoked when the indication of the configured CANRXPDUID
will be received by an Rx indication event from the CAN Driver module.
If no upper layer (UL) module is configured, no <User_RxIndication> has to be called in case of
an Rx indication event of the CANRXPDUID from the CAN Driver module.
Range:	CAN_NM		CAN NM
		CAN_TP 		CAN TP
		CAN_TSYN	Global Time Synchronization over CAN
		CDD 		Complex Driver
		J1939NM 	J1939Nm
		J1939TP 	J1939Tp
		PDUR 		PDU Router
		XCP 		Extended Calibration Protocol 
Note: If receive indications are not necessary or no upper layer modules
are configured for receive indications and thus <User_RxIndication>()
shall not be called, CANIF_RXPDU_USERRXINDICATION_UL and
CANIF_RXPDU_USERRXINDICATION_NAME need not to be configured. */
typedef uint8 CANIF_RXPDU_USERRXINDICATION_UL;
#define CAN_NM								((CANIF_RXPDU_USERRXINDICATION_UL)0x00U)
#define CAN_TP								((CANIF_RXPDU_USERRXINDICATION_UL)0x01U)
#define CAN_TSYN							((CANIF_RXPDU_USERRXINDICATION_UL)0x02U)
#define CDD									((CANIF_RXPDU_USERRXINDICATION_UL)0x03U)
#define J1939NM								((CANIF_RXPDU_USERRXINDICATION_UL)0x04U)
#define J1939TP								((CANIF_RXPDU_USERRXINDICATION_UL)0x05U)
#define PDUR								((CANIF_RXPDU_USERRXINDICATION_UL)0x06U)
#define XCP									((CANIF_RXPDU_USERRXINDICATION_UL)0x07U)

/* This parameter defines the name of the <User_RxIndication>. This parameter depends
on the parameter CanIfRxPduUserRxIndicationUL. If CanIfRxPduUserRxIndicationUL equals
CAN_TP, CAN_NM, PDUR, XCP, CAN_TSYN, J1939NM or J1939TP, the name of the <User_RxIndication> is fixed.
If CanIfRxPduUserRxIndicationUL equals CDD, the name of the <User_RxIndication> is selectable.

Note: If receive indications are not necessary or no upper layer modules are configured
for receive indications and thus <User_RxIndication>() shall not be called, CANIF_RXPDU_USERRXINDICATION_UL
and CANIF_RXPDU_USERRXINDICATION_NAME need not to be configured. */
#if(CanIfRxPduUserRxIndicationUL==PDUR)
	#define CanIfRxPduUserRxIndicationName		PduR_CanIfRxIndication
#else if(CanIfRxPduUserRxIndicationUL==CAN_NM)
	#define CanIfRxPduUserRxIndicationName		CanNm_RxIndication
#else if(CanIfRxPduUserRxIndicationUL==J1939NM)
	#define CanIfRxPduUserRxIndicationName		J1939Nm_RxIndication
#else if(CanIfRxPduUserRxIndicationUL==J1939TP)
	#define CanIfRxPduUserRxIndicationName		J1939Tp_RxIndication
#else if(CanIfRxPduUserRxIndicationUL==CAN_TP)
	#define CanIfRxPduUserRxIndicationName		CanTp_RxIndication
#else if(CanIfRxPduUserRxIndicationUL==XCP)
	#define CanIfRxPduUserRxIndicationName		Xcp_CanIfRxIndication
#else if(CanIfRxPduUserRxIndicationUL==CAN_TSYN)
	#define CanIfRxPduUserRxIndicationName		CanTSyn_CanIfRxIndication

#else if(CanIfRxPduUserRxIndicationUL==CDD)
	#define CanIfRxPduUserRxIndicationName		CDD_CanIfRxIndication /* Selectable */
#endif	

#endif /* __CANIF_CFG_H__ */
