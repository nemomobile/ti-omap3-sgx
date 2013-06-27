/*!****************************************************************************
@File           sgxapi_km.h

@Title          SGX KM API Header

@Author         Imagination Technologies

@Date           01/06/2004

@Copyright      Copyright 2004-2007 by Imagination Technologies Limited.
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
$Log: sgxapi_km.h $

services4\srvkm\devices\sgx\sgxinit.c:
Added maximum rate values to non-rate counters. Time-stamp timing-buffer
reads. Changed KickTA and KickTARender counters to output diffs, not
absolute values.
 --- Revision Logs Removed --- 
******************************************************************************/

#ifndef __SGXAPI_KM_H__
#define __SGXAPI_KM_H__

#if defined (__cplusplus)
extern "C" {
#endif

#include "sgxdefs.h"

#if defined(__linux__) && !defined(USE_CODE)
	#if defined(__KERNEL__)
		#include <asm/unistd.h>
	#else
		#include <unistd.h>
	#endif
#endif

/******************************************************************************
 Some defines...
******************************************************************************/

/* SGX Heap IDs, note: not all heaps are available to clients */
#define SGX_UNDEFINED_HEAP_ID				(~0LU)
#define SGX_GENERAL_HEAP_ID					0
#define SGX_TADATA_HEAP_ID					1
#define SGX_KERNEL_CODE_HEAP_ID				2
#define SGX_KERNEL_DATA_HEAP_ID				3
#define SGX_PIXELSHADER_HEAP_ID				4
#define SGX_VERTEXSHADER_HEAP_ID			5
#define SGX_PDSPIXEL_CODEDATA_HEAP_ID		6
#define SGX_PDSVERTEX_CODEDATA_HEAP_ID		7
#define SGX_SYNCINFO_HEAP_ID				8
#define SGX_3DPARAMETERS_HEAP_ID			9
#if defined(SUPPORT_SGX_GENERAL_MAPPING_HEAP)
	#define SGX_GENERAL_MAPPING_HEAP_ID			10
	#if defined(SGX_FEATURE_2D_HARDWARE)
		#define SGX_2D_HEAP_ID					11
		#define SGX_MAX_HEAP_ID					12
	#else
		#define SGX_MAX_HEAP_ID					11
	#endif
#else
	#if defined(SGX_FEATURE_2D_HARDWARE)
		#define SGX_2D_HEAP_ID					10
		#define SGX_MAX_HEAP_ID					11
	#else
		#define SGX_MAX_HEAP_ID					10
	#endif
#endif

#define SGX_MAX_TA_STATUS_VALS	32
#define SGX_MAX_3D_STATUS_VALS	4

/* sync info structure array size */
#define SGX_MAX_SRC_SYNCS			4

#ifdef SUPPORT_SGX_HWPERF

#define	PVRSRV_SGX_HWPERF_NUM_COUNTERS	9

#define PVRSRV_SGX_HWPERF_INVALID					0x1

#define PVRSRV_SGX_HWPERF_TRANSFER					0x2
#define PVRSRV_SGX_HWPERF_TA						0x3
#define PVRSRV_SGX_HWPERF_3D						0x4
#define PVRSRV_SGX_HWPERF_2D						0x5

#define PVRSRV_SGX_HWPERF_MK_EVENT					0x101
#define PVRSRV_SGX_HWPERF_MK_TA						0x102
#define PVRSRV_SGX_HWPERF_MK_3D						0x103
#define PVRSRV_SGX_HWPERF_MK_2D						0x104

#define PVRSRV_SGX_HWPERF_TYPE_STARTEND_BIT			28
#define PVRSRV_SGX_HWPERF_TYPE_OP_MASK				((1 << PVRSRV_SGX_HWPERF_TYPE_STARTEND_BIT) - 1)
#define PVRSRV_SGX_HWPERF_TYPE_OP_START				(0 << PVRSRV_SGX_HWPERF_TYPE_STARTEND_BIT)
#define PVRSRV_SGX_HWPERF_TYPE_OP_END				(1 << PVRSRV_SGX_HWPERF_TYPE_STARTEND_BIT)

#define PVRSRV_SGX_HWPERF_TYPE_TRANSFER_START		(PVRSRV_SGX_HWPERF_TRANSFER | PVRSRV_SGX_HWPERF_TYPE_OP_START)
#define PVRSRV_SGX_HWPERF_TYPE_TRANSFER_END			(PVRSRV_SGX_HWPERF_TRANSFER | PVRSRV_SGX_HWPERF_TYPE_OP_END)
#define PVRSRV_SGX_HWPERF_TYPE_TA_START				(PVRSRV_SGX_HWPERF_TA | PVRSRV_SGX_HWPERF_TYPE_OP_START)
#define PVRSRV_SGX_HWPERF_TYPE_TA_END				(PVRSRV_SGX_HWPERF_TA | PVRSRV_SGX_HWPERF_TYPE_OP_END)
#define PVRSRV_SGX_HWPERF_TYPE_3D_START				(PVRSRV_SGX_HWPERF_3D | PVRSRV_SGX_HWPERF_TYPE_OP_START)
#define PVRSRV_SGX_HWPERF_TYPE_3D_END				(PVRSRV_SGX_HWPERF_3D | PVRSRV_SGX_HWPERF_TYPE_OP_END)
#define PVRSRV_SGX_HWPERF_TYPE_2D_START				(PVRSRV_SGX_HWPERF_2D | PVRSRV_SGX_HWPERF_TYPE_OP_START)
#define PVRSRV_SGX_HWPERF_TYPE_2D_END				(PVRSRV_SGX_HWPERF_2D | PVRSRV_SGX_HWPERF_TYPE_OP_END)

#define PVRSRV_SGX_HWPERF_TYPE_MK_EVENT_START		(PVRSRV_SGX_HWPERF_MK_EVENT | PVRSRV_SGX_HWPERF_TYPE_OP_START)
#define PVRSRV_SGX_HWPERF_TYPE_MK_EVENT_END			(PVRSRV_SGX_HWPERF_MK_EVENT | PVRSRV_SGX_HWPERF_TYPE_OP_END)
#define PVRSRV_SGX_HWPERF_TYPE_MK_TA_START			(PVRSRV_SGX_HWPERF_MK_TA | PVRSRV_SGX_HWPERF_TYPE_OP_START)
#define PVRSRV_SGX_HWPERF_TYPE_MK_TA_END			(PVRSRV_SGX_HWPERF_MK_TA | PVRSRV_SGX_HWPERF_TYPE_OP_END)
#define PVRSRV_SGX_HWPERF_TYPE_MK_3D_START			(PVRSRV_SGX_HWPERF_MK_3D | PVRSRV_SGX_HWPERF_TYPE_OP_START)
#define PVRSRV_SGX_HWPERF_TYPE_MK_3D_END			(PVRSRV_SGX_HWPERF_MK_3D | PVRSRV_SGX_HWPERF_TYPE_OP_END)
#define PVRSRV_SGX_HWPERF_TYPE_MK_2D_START			(PVRSRV_SGX_HWPERF_MK_2D | PVRSRV_SGX_HWPERF_TYPE_OP_START)
#define PVRSRV_SGX_HWPERF_TYPE_MK_2D_END			(PVRSRV_SGX_HWPERF_MK_2D | PVRSRV_SGX_HWPERF_TYPE_OP_END)

#define PVRSRV_SGX_HWPERF_OFF						(0x0)
#define PVRSRV_SGX_HWPERF_GRAPHICS_ON				(1UL << 0)
#define PVRSRV_SGX_HWPERF_MK_EXECUTION_ON			(1UL << 1)


/*!
 *****************************************************************************
 * One entry in the HWPerf Circular Buffer. 
 *****************************************************************************/
typedef struct _PVRSRV_SGX_HWPERF_CB_ENTRY_
{
	IMG_UINT32	ui32FrameNo;
	IMG_UINT32	ui32Type;
	IMG_UINT32	ui32Ordinal;
	IMG_UINT32	ui32Clocksx16;
	IMG_UINT32	ui32Counters[PVRSRV_SGX_HWPERF_NUM_COUNTERS];
} PVRSRV_SGX_HWPERF_CB_ENTRY;


/*!
 *****************************************************************************
 * (Deprecated) One packet in the HWPerf CB. 
 *****************************************************************************/
typedef struct _PVRSRV_SGX_HWPERF_CBDATA_
{
	IMG_UINT32	ui32FrameNo;
	IMG_UINT32	ui32Type;
	IMG_UINT32	ui32StartTimeWraps;
	IMG_UINT32	ui32StartTime;
	IMG_UINT32	ui32EndTimeWraps;
	IMG_UINT32	ui32EndTime;
	IMG_UINT32	ui32ClockSpeed;
	IMG_UINT32	ui32TimeMax;
} PVRSRV_SGX_HWPERF_CBDATA;


/*!
 *****************************************************************************
 * (Deprecated) Structure for misc SGX command to retrieve CB info 
 *****************************************************************************/
typedef struct _SGX_MISC_INFO_HWPERF_RETRIEVE_CB
{
	PVRSRV_SGX_HWPERF_CBDATA*	psHWPerfData;	/*!< out: if not 0, array of current values */
	IMG_UINT32					ui32ArraySize;	/*!< In: max num of retrieved data packets*/
	IMG_UINT32					ui32DataCount;	/*!< out: the number of supplied data packets*/
	IMG_UINT32					ui32Time;		/*!< out: the CPU time (microseconds) */
} SGX_MISC_INFO_HWPERF_RETRIEVE_CB;
#endif /* SUPPORT_SGX_HWPERF */


/*
	Status values control structure
*/
typedef struct _CTL_STATUS_
{
	IMG_DEV_VIRTADDR	sStatusDevAddr;
	IMG_UINT32			ui32StatusValue;
} CTL_STATUS;


/*!
	List of possible requests/commands to SGXGetMiscInfo()
*/
typedef enum _SGX_MISC_INFO_REQUEST_
{
	SGX_MISC_INFO_REQUEST_CLOCKSPEED = 0,
	SGX_MISC_INFO_REQUEST_SGXREV,
	SGX_MISC_INFO_REQUEST_DRIVER_SGXREV,
#if defined(SUPPORT_SGX_HWPERF)
	SGX_MISC_INFO_REQUEST_SET_HWPERF_STATUS,
	SGX_MISC_INFO_REQUEST_HWPERF_CB_ON, /* deprecated */
	SGX_MISC_INFO_REQUEST_HWPERF_CB_OFF, /* deprecated */
	SGX_MISC_INFO_REQUEST_HWPERF_RETRIEVE_CB, /* deprecated */
#endif /* SUPPORT_SGX_HWPERF */
	SGX_MISC_INFO_REQUEST_FORCE_I16 				=  0x7fff
} SGX_MISC_INFO_REQUEST;


/******************************************************************************
 * Struct for passing SGX core rev/features from ukernel to driver.
 * This is accessed from the kernel part of the driver and microkernel; it is
 * only accessed in user space during buffer allocation in srvinit.
 ******************************************************************************/
typedef struct _PVRSRV_SGX_MISCINFO_FEATURES
{
	IMG_UINT32			ui32CoreRev;	/*!< SGX Core revision from HW register */
	IMG_UINT32			ui32CoreID;		/*!< SGX Core ID from HW register */
	IMG_UINT32			ui32DDKVersion;	/*!< software DDK version */
	IMG_UINT32			ui32DDKBuild;	/*!< software DDK build no. */
	IMG_UINT32			ui32CoreIdSW;	/*!< software core version (ID), e.g. SGX535, SGX540 */
	IMG_UINT32			ui32CoreRevSW;	/*!< software core revision */
	IMG_UINT32			ui32BuildOptions;	/*!< build options bit-field */
} PVRSRV_SGX_MISCINFO_FEATURES;

/*!
 ******************************************************************************
 * Structure for misc SGX commands in services
 *****************************************************************************/
typedef struct _SGX_MISC_INFO_
{
	SGX_MISC_INFO_REQUEST	eRequest;	/*!< Command request to SGXGetMiscInfo() */

	union
	{
		IMG_UINT32	reserved;	/*!< Unused: ensures valid code in the case everything else is compiled out */
		PVRSRV_SGX_MISCINFO_FEATURES						sSGXFeatures;
		IMG_UINT32											ui32SGXClockSpeed;
#ifdef SUPPORT_SGX_HWPERF
		IMG_UINT32											ui32NewHWPerfStatus;
		SGX_MISC_INFO_HWPERF_RETRIEVE_CB					sRetrieveCB;
#endif /* SUPPORT_SGX_HWPERF */
	} uData;
} SGX_MISC_INFO;

#if defined(SGX_FEATURE_2D_HARDWARE)
/*
 * The largest number of source sync objects that can be associated with a blit
 * command.  Allows for src, pattern, and mask
 */
#define PVRSRV_MAX_BLT_SRC_SYNCS		3
#endif

enum render_state_buf_type {
	RSB_USSE_VERTEX_PROG,
	RSB_USSE_FRAGMENT_PROG,
};

struct render_state_buf_info {
	IMG_UINT32			buf_id;
	IMG_UINT32			offset;
	IMG_UINT32			size;
	enum render_state_buf_type	type;
};

struct render_state_buf_list {
	IMG_UINT32			cnt;
	struct render_state_buf_info	info[20];
};

#define SGX_KICKTA_DUMPBITMAP_MAX_NAME_LENGTH		256

/*
	Structure for dumping bitmaps
*/
typedef struct _SGX_KICKTA_DUMPBITMAP_
{
	IMG_DEV_VIRTADDR	sDevBaseAddr;
	IMG_UINT32			ui32Flags;
	IMG_UINT32			ui32Width;
	IMG_UINT32			ui32Height;
	IMG_UINT32			ui32Stride;
	IMG_UINT32			ui32PDUMPFormat;
	IMG_UINT32			ui32BytesPP;
	IMG_CHAR			pszName[SGX_KICKTA_DUMPBITMAP_MAX_NAME_LENGTH];
} SGX_KICKTA_DUMPBITMAP, *PSGX_KICKTA_DUMPBITMAP;

#define PVRSRV_SGX_PDUMP_CONTEXT_MAX_BITMAP_ARRAY_SIZE	(16)

/*!
 ******************************************************************************
 * Data required only when dumping parameters
 *****************************************************************************/
typedef struct _PVRSRV_SGX_PDUMP_CONTEXT_
{
	/* cache control word for micro kernel cache flush/invalidates */
	IMG_UINT32						ui32CacheControl;

} PVRSRV_SGX_PDUMP_CONTEXT;


typedef struct _SGX_KICKTA_DUMP_ROFF_
{
	IMG_HANDLE			hKernelMemInfo;						/*< Buffer handle */
	IMG_UINT32			uiAllocIndex;						/*< Alloc index for LDDM */
	IMG_UINT32			ui32Offset;							/*< Byte offset to value to dump */
	IMG_UINT32			ui32Value;							/*< Actual value to dump */
	IMG_PCHAR			pszName;							/*< Name of buffer */
} SGX_KICKTA_DUMP_ROFF, *PSGX_KICKTA_DUMP_ROFF;

typedef struct _SGX_KICKTA_DUMP_BUFFER_
{
	IMG_UINT32			ui32SpaceUsed;
	IMG_UINT32			ui32Start;							/*< Byte offset of start to dump */
	IMG_UINT32			ui32End;							/*< Byte offset of end of dump (non-inclusive) */
	IMG_UINT32			ui32BufferSize;						/*< Size of buffer */
	IMG_UINT32			ui32BackEndLength;					/*< Size of back end portion, if End < Start */
	IMG_UINT32			uiAllocIndex;
	IMG_HANDLE			hKernelMemInfo;						/*< MemInfo handle for the circular buffer */
	IMG_PVOID			pvLinAddr;
#if defined(SUPPORT_SGX_NEW_STATUS_VALS)
	IMG_HANDLE			hCtrlKernelMemInfo;					/*< MemInfo handle for the control structure of the
																circular buffer */
	IMG_DEV_VIRTADDR	sCtrlDevVAddr;						/*< Device virtual address of the memory in the 
																control structure to be checked */
#endif
	IMG_PCHAR			pszName;							/*< Name of buffer */
} SGX_KICKTA_DUMP_BUFFER, *PSGX_KICKTA_DUMP_BUFFER;

#ifdef PDUMP
/*
	PDUMP version of above kick structure
*/
typedef struct _SGX_KICKTA_PDUMP_
{
	// Bitmaps to dump
	PSGX_KICKTA_DUMPBITMAP		psPDumpBitmapArray;
	IMG_UINT32						ui32PDumpBitmapSize;

	// Misc buffers to dump (e.g. TA, PDS etc..)
	PSGX_KICKTA_DUMP_BUFFER	psBufferArray;
	IMG_UINT32						ui32BufferArraySize;

	// Roffs to dump
	PSGX_KICKTA_DUMP_ROFF		psROffArray;
	IMG_UINT32						ui32ROffArraySize;
} SGX_KICKTA_PDUMP, *PSGX_KICKTA_PDUMP;
#endif	/* PDUMP */

#if defined(TRANSFER_QUEUE)
#if defined(SGX_FEATURE_2D_HARDWARE)
/* Maximum size of ctrl stream for 2d blit command (in 32 bit words) */
#define SGX_MAX_2D_BLIT_CMD_SIZE 		26
#define SGX_MAX_2D_SRC_SYNC_OPS			3
#endif
#define SGX_MAX_TRANSFER_STATUS_VALS	2	
#define SGX_MAX_TRANSFER_SYNC_OPS	5
#endif

enum pvr_sync_wait_seq_type {
	_PVR_SYNC_WAIT_BLOCK,
	_PVR_SYNC_WAIT_NONBLOCK,
	_PVR_SYNC_WAIT_EVENT,
	_PVR_SYNC_WAIT_FLIP,
	_PVR_SYNC_WAIT_UPDATE,
};

#if defined (__cplusplus)
}
#endif

#endif /* __SGXAPI_KM_H__ */

/******************************************************************************
 End of file (sgxapi.h)
******************************************************************************/
