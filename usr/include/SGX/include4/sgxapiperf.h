/*!****************************************************************************
@File           sgxapiperf.h

@Title          SGX API Header (Performance profiling)

@Author         Imagination Technologies

@Date           11/04/2007

@Copyright      Copyright 2007 by Imagination Technologies Limited.
                All rights reserved. No part of this software, either material
                or conceptual may be copied or distributed, transmitted,
                transcribed, stored in a retrieval system or translated into
                any human or computer language in any form by any means,
                electronic, mechanical, manual or otherwise, or disclosed
                to third parties without the express written permission of
                Imagination Technologies Limited, Home Park Estate,
                Kings Langley, Hertfordshire, WD4 8LZ, U.K.

@Platform       Cross platform / environment

@Description    Exported SGX API details

@DoxygenVer

******************************************************************************/
/******************************************************************************
Modifications :-
$Log: sgxapiperf.h $
,
 --- Revision Logs Removed --- 
******************************************************************************/

#ifndef __SGXAPIPERF_H__
#define __SGXAPIPERF_H__

#if defined (__cplusplus)
extern "C" {
#endif


/****************************************************************************/
/* Performance registers													*/
/****************************************************************************/

/*!
	List of performance counters available from SGX devices
*/
typedef enum _SGX_HWPERF_NAME_
{
	SGX_HWPERF_SW_ACTIVE_GROUP	= 0,
	SGX_HWPERF_SW_TIME,
	SGX_HWPERF_SW_SGX_AWAKE,
	SGX_HWPERF_HW_TIME_WRAPS,
	SGX_HWPERF_KICKTA,
	SGX_HWPERF_KICKTARENDER,

	SGX_HWPERF_ZERO,
	SGX_HWPERF_NINE				= SGX_HWPERF_ZERO + 9,

	SGX_HWPERF_VALUE_COUNT,

	SGX_HWPERF_FORCE_I16 				=  0x7fff
} SGX_HWPERF_NAME;

/*!
 ******************************************************************************
 * Structure for SGX command to query current counter values
 *****************************************************************************/
typedef struct _SGX_HWPERF_COUNTERS_
{
	IMG_UINT32	*pui32Values;	/*!< out: array of current values (length SGX_HWPERF_VALUE_COUNT) */
	IMG_UINT32	ui32PerfGroup;	/*!< in: if a valid group, changes the HW's active group (after reading current values) */
	IMG_BOOL	bResetCounters;	/*!< in: if true, reset the counters when changing the group */
} SGX_HWPERF_COUNTERS;


IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXGetHWPerfCounters(PVRSRV_DEV_DATA		*psDevData,
											   SGX_HWPERF_COUNTERS	*psHWPerfCounters);

IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXReadHWPerfCB(PVRSRV_DEV_DATA				*psDevData,
										  IMG_UINT32					ui32ArraySize,
										  PVRSRV_SGX_HWPERF_CB_ENTRY	*psHWPerfCBData,
										  IMG_UINT32					*pui32DataCount,
										  IMG_UINT32					*pui32ClockSpeed,
										  IMG_UINT32					*pui32HostTimeStamp);

#if defined (__cplusplus)
}
#endif

#endif /* __SGXAPIPERF_H__ */

/******************************************************************************
 End of file (sgxapiperf.h)
******************************************************************************/
