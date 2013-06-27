/*!****************************************************************************
@File           sgxapi.h

@Title          SGX API Header

@Author         Imagination Technologies

@Date           01/06/2004

@Copyright      Copyright 2004-2008 by Imagination Technologies Limited.
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
$Log: sgxapi.h $
******************************************************************************/

#ifndef __SGXAPI_H__
#define __SGXAPI_H__

#if defined (__cplusplus)
extern "C" {
#endif

#include "sgxdefs.h"

#if defined(__linux__) && !defined(USE_CODE)
	#include <string.h>
	#if defined(__KERNEL__)
		#include <asm/unistd.h>
	#else
		#include <unistd.h>
	#endif
#endif

#include "sgxapi_km.h"
#ifdef SUPPORT_SGX_HWPERF
#include "sgxapiperf.h"
#endif

/*
	SGX USSE code execution register base indices
*/
#define SGX_PIXSHADER_USE_CODE_BASE_INDEX	0
#define SGX_VTXSHADER_USE_CODE_BASE_INDEX	10

/******************************************************************************
 Local ISR handler structures
******************************************************************************/

#define SGXISR_FLAG_CRTC_VSYNC		0x0001
#define SGXISR_FLAG_DMA_COMPLETE	0x0002
#define SGXISR_FLAG_DMA_PREEMPTED	0x0004
#define SGXISR_FLAG_DMA_FAULTED		0x0008

typedef struct _SGXISRINFO
{
	IMG_HANDLE	hDevCookie;		/* input */
	IMG_UINT32	ui32Flags;		/* returns flag settings relating to interrupts */
	IMG_BOOL	bInterruptProcessed; /* set to IMG_TRUE to let the calee know that the 
										Flags are valid */
} SGXISRINFO, *PSGXISRINFO;



/******************************************************************************
 Visibility test back door condition defines
******************************************************************************/
#define BDVISTEST_COND_ALWAYS				0x00000000
#define BDVISTEST_COND_EQUAL				0x00000001
#define BDVISTEST_COND_LSEQUAL				0x00000002
#define BDVISTEST_COND_GREQUAL				0x00000003
#define BDVISTEST_COND_MASK					0x00000003

#define BDVISTEST_REG_MASK					0x0000001C
#define BDVISTEST_REG_SHIFT					2

#define BDVISTEST_VAL_MASK					0xFFFFFFE0
#define BDVISTEST_VAL_SHIFT					5

/******************************************************************************
 Structures used in API calls
******************************************************************************/

/*
	Maximum number of queued renders per render target
*/
#define SGX_MAX_QUEUED_RENDERS			3

#if defined(SUPPORT_SGX_PRIORITY_SCHEDULING)
#define SGX_MAX_CONTEXT_PRIORITY		3
#else
#define SGX_MAX_CONTEXT_PRIORITY		1
#endif

/*
	SGX render context scheduling priority
*/
typedef enum _SGX_CONTEXT_PRIORITY_
{
	SGX_CONTEXT_PRIORITY_LOW	= 0,
	SGX_CONTEXT_PRIORITY_MEDIUM	= 1,
	SGX_CONTEXT_PRIORITY_HIGH	= 2,
	SGX_CONTEXT_PRIORITY_FORCE_I32	= 0x7fffffff
} SGX_CONTEXT_PRIORITY;

typedef struct _SGX_CREATERENDERCONTEXT_
{
	IMG_UINT32				ui32Flags;
	IMG_HANDLE				hDevCookie;
	IMG_HANDLE				hDevMemContext;
	IMG_HANDLE				hOSEvent;
	IMG_UINT32				ui32PBSize;
	IMG_UINT32				ui32VisTestResultBufferSize;
} SGX_CREATERENDERCONTEXT, *PSGX_CREATERENDERCONTEXT;

#define SGX_CREATERCTXTFLAGS_SHAREDPB	0x00000001

typedef enum _SGX_SCALING_
{
	SGX_SCALING_NONE = 0,
	SGX_DOWNSCALING,
	SGX_UPSCALING,
	SGX_SCALING_FORCE_I32 = 0x7FFFFFFF
} SGX_SCALING;

typedef struct _SGX_ADDRENDTARG_
{
	IMG_UINT32				ui32Flags;
	IMG_HANDLE				hRenderContext;
	IMG_HANDLE				hDevCookie;
	IMG_UINT32				ui32NumPixelsX;
	IMG_UINT32				ui32NumPixelsY;
	IMG_UINT16				ui16MSAASamplesInX;
	IMG_UINT16				ui16MSAASamplesInY;
	SGX_SCALING				eForceScalingInX;
	SGX_SCALING				eForceScalingInY;
	IMG_UINT32				ui32BGObjUCoord;	/* Texture U-coordinate of right-hand vertex of background object */
	PVRSRV_ROTATION			eRotation;
#if defined(SGX_FEATURE_RENDER_TARGET_ARRAYS)
	IMG_UINT16				ui16NumRTsInArray;
#endif
} SGX_ADDRENDTARG, *PSGX_ADDRENDTARG;

#define SGX_ADDRTFLAGS_SHAREDRTDATA				0x00000001
#define SGX_ADDRTFLAGS_USEOGLMODE					0x00000002
#define SGX_ADDRTFLAGS_FORCE_MT_MODE_SELECT		0x00000004

#define SGX_KICKTA_FLAGS_RESETTPC						0x00000001
#define SGX_KICKTA_FLAGS_KICKRENDER					0x00000002
#define SGX_KICKTA_FLAGS_FIRSTTAPROD					0x00000004
#define SGX_KICKTA_FLAGS_COLOURALPHAVALID				0x00000008
#define SGX_KICKTA_FLAGS_RENDEREDMIDSCENE				0x00000010
#define SGX_KICKTA_FLAGS_GETVISRESULTS					0x00000020
#define SGX_KICKTA_FLAGS_TAUSEDAFTERRENDER				0x00000040
#define SGX_KICKTA_FLAGS_RENDEREDMIDSCENENOFREE		0x00000080
#define SGX_KICKTA_FLAGS_TERMINATE						0x00000100
#define SGX_KICKTA_FLAGS_ABORT							0x00000200
#define SGX_KICKTA_FLAGS_VISTESTTERM					0x00000400
#define SGX_KICKTA_FLAGS_MIDSCENENOFREE				0x00000800
#define SGX_KICKTA_FLAGS_ZONLYRENDER					0x00001000
#define SGX_KICKTA_FLAGS_MIDSCENETERM					0x00002000
#define SGX_KICKTA_FLAGS_FLUSHDATACACHE				0x00004000 
#define SGX_KICKTA_FLAGS_FLUSHPDSCACHE					0x00008000
#define SGX_KICKTA_FLAGS_FLUSHUSECACHE					0x00010000
#define SGX_KICKTA_FLAGS_DEPTHBUFFER					0x00020000
#define SGX_KICKTA_FLAGS_STENCILBUFFER                                 0x00040000
#define SGX_KICKTA_FLAGS_TQTA_SYNC                                             0x00080000
#define SGX_KICKTA_FLAGS_TQ3D_SYNC                                             0x00100000
#define SGX_KICKTA_FLAGS_DEPENDENT_TA                                  0x00200000
#define SGX_KICKTA_FLAGS_TA_DEPENDENCY                                 0x00400000
#define SGX_KICKTA_FLAGS_TE_AA_GLOBALREGISTER                  0x00800000
#define SGX_KICKTA_FLAGS_COMPLEX_GEOMTERY_PRESENT              0x01000000

/* Host flags */
#define SGX_KICKTA_HOST_FLAGS_DEPTHCLEARED				0x10000000
#define SGX_KICKTA_HOST_FLAGS_STENCILCLEARED			0x20000000

/*!
 ******************************************************************************
 * Client device information structure for SGX
 *****************************************************************************/
typedef struct _PVRSRV_SGX_CLIENT_INFO_
{
	IMG_UINT32					ui32ProcessID;			/*!< ID of process controlling SGX device */
	IMG_VOID					*pvProcess;				/*!< pointer to OS specific 'process' structure */
	PVRSRV_MISC_INFO			sMiscInfo;				/*!< Misc. Information, inc. SOC specifics */

	IMG_UINT32					ui32EVMConfig;			/*!< used by pdumping kicks */
	IMG_UINT32					ui32ClientKickFlags;	/*!< misc flags used between kicks, per client */
	IMG_UINT32					ui32NumUSETemporaryRegisters;	/*!< Number of temporary registers available */
	IMG_UINT32					ui32NumUSEAttributeRegisters;	/*!< Number of attribute registers available */

	IMG_DEV_VIRTADDR			uPDSExecBase;

	IMG_DEV_VIRTADDR			uUSEExecBase;

} PVRSRV_SGX_CLIENT_INFO;


/*!
 ******************************************************************************
 * Internal device information structure for SGX
 *****************************************************************************/
typedef struct _PVRSRV_SGX_INTERNALDEV_INFO
{
	IMG_UINT32			ui32Flags;
	IMG_BOOL			bPDSTimerEnable;
	IMG_HANDLE			hHostCtlKernelMemInfoHandle;
	IMG_DEV_VIRTADDR	sDummyStencilLoadDevVaddr;
	IMG_DEV_VIRTADDR	sDummyStencilStoreDevVAddr;
	IMG_BOOL			bForcePTOff;
	IMG_UINT32			ui32RegFlags;
}PVRSRV_SGX_INTERNALDEV_INFO;


/*
	Structures for KickTA API
*/
#if defined(SGX_FEATURE_VDM_CONTEXT_SWITCH_REV_2)
#define SGX_MAX_VDM_STATE_RESTORE_PROGS		(2)

typedef struct _SGX_VDM_STATE_RESTORE_DATA_
{
    IMG_UINT32       ui32StateWord0;
    IMG_UINT32       ui32StateWord1;
} SGX_VDM_STATE_RESTORE_DATA;
#endif

typedef struct _SGX_KICKTA_COMMON_
{
	IMG_UINT32			ui32Frame;

	IMG_UINT32			ui32KickFlags;			/*!< Combination of SGX_KICKTA_FLAGS_xxxx flags */

	/* These are used for communication within the driver and are not of interest to the 
	 * uKernel or Services */
	IMG_UINT32			ui32HostFlags; 			/*!< A combination of SGX_KICKTA_HOST_FLAGS_xxx flags */

	IMG_BOOL			bCheckZLSControl;		/* FIXME: remove this */
	IMG_UINT32			ui32StoreEnable;		/* FIXME: remove this */

	IMG_HANDLE			hRenderContext;
	IMG_HANDLE			hRTDataSet;

	IMG_DEV_VIRTADDR	sVisTestResultMem;
	IMG_UINT32			ui32VisTestFlags;
	IMG_UINT32			ui32VisBreakpointCount;

#if defined(SGX_FEATURE_VDM_CONTEXT_SWITCH) || defined(SGX_FEATURE_VDM_CONTEXT_SWITCH_REV_2)
#if defined(SGX_FEATURE_VDM_CONTEXT_SWITCH_REV_2)
	IMG_DEV_VIRTADDR	sVDMSARestoreDataDevAddr[SGX_MAX_VDM_STATE_RESTORE_PROGS];
#endif
	IMG_DEV_VIRTADDR	sTAStateShadowDevAddr;
#endif

	IMG_UINT32			ui32ISPBGObjDepth;
	IMG_UINT32			ui32ISPBGObj;
	IMG_UINT32			ui32ISPIPFMisc;
	#ifndef SGX545
	IMG_UINT32			ui32ISPPerpendicular;
	IMG_UINT32			ui32ISPCullValue;
	#else
	IMG_UINT32			ui32GSGBase;
	IMG_UINT32			ui32GSGStride;
	IMG_UINT32			ui32GSGWrapAddr;
	IMG_UINT32			ui32GSGStateStoreBase;
	IMG_UINT32			ui321stPhaseComplexGeomBufferBase;
	IMG_UINT32			ui321stPhaseComplexGeomBufferSize;
	IMG_UINT32			ui32VtxBufWritePointerPDSProgBaseAddr;
	IMG_UINT32			ui32VtxBufWritePointerPDSProgDataSize;
	IMG_UINT32			ui32SCWordCopyProgram;
	IMG_UINT32			ui32ITPProgram;
	IMG_UINT32			ui32OrderDepAASampleGrid;
	IMG_UINT32			ui32OrderDepAASampleGrid2;
	IMG_UINT32			ui32DoublePixelPartitions;
	#endif
	#if defined(SGX_FEATURE_ZLS_EXTERNALZ)
	IMG_DEV_VIRTADDR	sISPZLoadBase;
	IMG_DEV_VIRTADDR	sISPStencilLoadBase;
	IMG_DEV_VIRTADDR	sISPZStoreBase;
	IMG_DEV_VIRTADDR	sISPStencilStoreBase;
	#else
	IMG_DEV_VIRTADDR	sISPZBase;
	IMG_DEV_VIRTADDR	sISPStencilBase;
	#endif
	IMG_BOOL			bSeperateStencilLoadStore;
	IMG_UINT32			ui32ZLSCtl;
	IMG_UINT32			ui32ISPValidId;
	IMG_UINT32			ui32ISPDBias;
	IMG_UINT32			ui32ISPSceneBGObj;

	IMG_UINT32			ui32EDMPixelPDSAddr;
	IMG_UINT32			ui32EDMPixelPDSDataSize;
	IMG_UINT32			ui32EDMPixelPDSInfo;

	IMG_UINT32			ui32PixelBE;

	IMG_UINT32			ui32Filter0Left;
#if defined(SGX_FEATURE_USE_HIGH_PRECISION_FIR_COEFF)
	IMG_UINT32			ui32Filter0Centre;
#endif
	IMG_UINT32			ui32Filter0Right;
	IMG_UINT32			ui32Filter0Extra;
	IMG_UINT32			ui32Filter1Left;
#if defined(SGX_FEATURE_USE_HIGH_PRECISION_FIR_COEFF)
	IMG_UINT32			ui32Filter1Centre;
#endif
	IMG_UINT32			ui32Filter1Right;
	IMG_UINT32			ui32Filter1Extra;
	IMG_UINT32			ui32Filter2Left;
	IMG_UINT32			ui32Filter2Right;
	IMG_UINT32			ui32Filter2Extra;
	IMG_UINT32			ui32FilterTable;
	IMG_UINT32			ui32USEStoreRange;
	IMG_UINT32			ui32USELoadRedirect;
#if defined(SUPPORT_DISPLAYCONTROLLER_TILING)
	IMG_UINT32			ui32BIFTile0Config;
#endif
	/*
		TA Ctrl stream base
	*/
	IMG_DEV_VIRTADDR	sTABufferCtlStreamBase;
	/*
		Address of terminate in control stream
	*/
	IMG_DEV_VIRTADDR	sTABufferCtlStreamTerminate;

	IMG_UINT32			ui32MTECtrl;

	IMG_UINT32			aui32SpecObject[3];			/*!< 3 words for PDS hardware background object */

	IMG_UINT32			ui32NumTAStatusVals;
	IMG_UINT32			ui32Num3DStatusVals;
	IMG_UINT32			ui32NumSrcSyncs;


} SGX_KICKTA_COMMON;

#if defined(TRANSFER_QUEUE)
#define SGX_MAX_TRANSFER_UPDATES		5	
#if defined(SGXTQ_PREP_SUBMIT_SEPERATE)
#define SGXTQ_MAX_COMMANDS 96 /* 10 mipmap levels for 128bit textures */
#else
#define SGXTQ_MAX_COMMANDS 1 /* 10 mipmap levels for 128bit textures */
#endif
#define SGXTQ_MAX_SURFACES				3
#define SGXTQ_MAX_RECTS					3
#endif

typedef struct _SGX_STATUS_UPDATE_
{
	CTL_STATUS				sCtlStatus;
	IMG_HANDLE				hKernelMemInfo;
} SGX_STATUS_UPDATE;

typedef struct _SGX_KICKTA_
{
	SGX_KICKTA_COMMON sKickTACommon;

#if defined(SGX_FEATURE_RENDER_TARGET_ARRAYS)
	PVRSRV_CLIENT_SYNC_INFO	**ppsRenderSurfSyncInfo;
	IMG_DEV_VIRTADDR 	sPixEventUpdateDevAddr;
	IMG_UINT32			*psPixEventUpdateList;
	IMG_UINT32			*psHWBgObjPrimPDSUpdateList;
#else
	PVRSRV_CLIENT_SYNC_INFO	*psRenderSurfSyncInfo;
#endif
	PVRSRV_CLIENT_SYNC_INFO *apsSrcSurfSyncInfo[SGX_MAX_SRC_SYNCS];

#if defined(SUPPORT_SGX_NEW_STATUS_VALS)
	SGX_STATUS_UPDATE		asTAStatusUpdate[SGX_MAX_TA_STATUS_VALS];
	SGX_STATUS_UPDATE		as3DStatusUpdate[SGX_MAX_3D_STATUS_VALS];
#else
	PVRSRV_CLIENT_SYNC_INFO	*apsTAStatusInfo[SGX_MAX_TA_STATUS_VALS];
	PVRSRV_CLIENT_SYNC_INFO	*aps3DStatusInfo[SGX_MAX_3D_STATUS_VALS];
#endif

	IMG_HANDLE			hTQContext;

	struct render_state_buf_list	render_state_bufs;

} SGX_KICKTA;

typedef struct _SGX_KICKTA_OUTPUT_
{
	IMG_BOOL			bSPMOutOfMemEvent;
	IMG_UINT32			ui32NumPBPagesFree;
#if defined(DEBUG) || defined(FORCE_PB_WATERMARK)
	IMG_UINT32			ui32AllocPagesWatermark;
	IMG_UINT32			ui32NumPBPages;
#endif
	IMG_UINT32			ui32MaxZTileX;
	IMG_UINT32			ui32MaxZTileY;

	PVRSRV_HWREG		*psZLSReg;
	IMG_PUINT32			pui32VDMBaseRegVal;

} SGX_KICKTA_OUTPUT;


/******************************************************************************
 General constants associated with interface
******************************************************************************/
#define SGX_SPECIALOBJECT_SIZE		512

#define SGX_USE_MINTEMPREGS		0


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
////////////////////////////new APIs///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


#define PVRSRV_SGX_HOSTRENDER_FORCECTXRESET				(0x00000001)


/*
	FIXME: allow pointer to Kernel CCB
	remove when the HAL stops queuing blits and migrates work to srvkm
*/

/*
	ui32ClientKickFlags
*/
#define PVRSRV_SGX_CLIENT_INFO_KICKFLAGS_DEFERWAITFORRENDERCOMPLETE		0x00000001
#define PVRSRV_SGX_CLIENT_INFO_KICKFLAGS_DEFERWAITFORFREE3DMEMORY		0x00000002

#if defined(TRANSFER_QUEUE)
/******************************************************************************
 * transfer queue structures
 *****************************************************************************/



/* enum types that are available to the client */


/* Filter type to use when performing operations */
typedef enum _SGXTQ_FILTERTYPE_
{
	SGXTQ_FILTERTYPE_POINT = 0,
	SGXTQ_FILTERTYPE_LINEAR,
	SGXTQ_FILTERTYPE_ANISOTROPIC
} SGXTQ_FILTERTYPE;

/* Colourkey */
typedef enum _SGXTQ_COLOURKEY_
{
	SGXTQ_COLOURKEY_NONE = 0,
	SGXTQ_COLOURKEY_SOURCE,
	SGXTQ_COLOURKEY_DEST
} SGXTQ_COLOURKEY;

/* Rotation */
typedef enum _SGXTQ_ROTATION_
{
	SGXTQ_ROTATION_NONE = 0,
	SGXTQ_ROTATION_90,
	SGXTQ_ROTATION_180,
	SGXTQ_ROTATION_270
} SGXTQ_ROTATION;

/* Alpha blend */
typedef enum _SGXTQ_ALPHA_
{
	SGXTQ_ALPHA_NONE = 0,
	SGXTQ_ALPHA_SOURCE,						/* Cdst = Csrc*Asrc		+ Cdst*(1-Asrc)				*/
	SGXTQ_ALPHA_PREMUL_SOURCE,				/* Cdst = Csrc			+ Cdst*(1-Asrc)				*/
	SGXTQ_ALPHA_GLOBAL,						/* Cdst = Csrc*Aglob	+ Cdst*(1-Aglob)			*/
	SGXTQ_ALPHA_PREMUL_SOURCE_WITH_GLOBAL	/* Cdst = Csrc*Aglob	+ Cdst*(1-Asrc)*(1-Aglob)	*/
} SGXTQ_ALPHA;

typedef enum _SGXTQ_MEMLAYOUT_
{
	SGXTQ_MEMLAYOUT_2D = 0,
	SGXTQ_MEMLAYOUT_3D,
	SGXTQ_MEMLAYOUT_CEM,
	SGXTQ_MEMLAYOUT_STRIDE,
	SGXTQ_MEMLAYOUT_TILED,
	SGXTQ_MEMLAYOUT_OUT_LINEAR,
	SGXTQ_MEMLAYOUT_OUT_TILED,
	SGXTQ_MEMLAYOUT_OUT_TWIDDLED
} SGXTQ_MEMLAYOUT;

/* Available transfer queue operation types */
typedef enum _SGXTQ_BLITTYPE_
{
	SGXTQ_BLIT = 1,
#if defined(SGX_FEATURE_2D_HARDWARE)
	SGXTQ_2DHWBLIT,
#endif
	SGXTQ_MIPGEN,
	SGXTQ_FILL,
	SGXTQ_BUFFERBLT,
	SGXTQ_CUSTOM,
	SGXTQ_FULL_CUSTOM,
	SGXTQ_TEXTURE_UPLOAD,
	SGXTQ_CLIP_BLIT,
	SGXTQ_CUSTOMSHADER_BLIT,
	SGXTQ_COLOURLUT_BLIT,

} SGXTQ_BLITTYPE;

/* Support structures that are used in transfer queue operations */

/* A surface describes a source or destination for a transfer operation */
typedef struct _SGXTQ_TQSURFACE_
{
	IMG_DEV_VIRTADDR	sDevVAddr;
	IMG_UINT32			ui32Width; /* In texels - Ignored for sources in custom blits */
	IMG_UINT32			ui32Height;  /* In texels - Ignored for sources in custom blits */
	IMG_INT32			i32StrideInBytes; /* In bytes - Ignored for sources in custom blits */
	PVRSRV_PIXEL_FORMAT	eFormat;    /* - Ignored for sources in custom blits */
	SGXTQ_MEMLAYOUT		eMemLayout; /* - Ignored for sources in custom blits */
	IMG_UINT32			ui32ChunkStride; /* Chunk stride for >32 bpp surfaces */
	PVRSRV_CLIENT_SYNC_INFO	*psSyncInfo;
} SGXTQ_SURFACE;

/* Entries specific to different blit types */

/* Blit operation is a copy from 1 source to 1 destination.
	Supported operations:
	- Stretch
	- Gamma
	- Format conversion
	- Rotation
	- Colour key
	- Alpha
	- Custom Rop
*/
typedef struct _SGXTQ_BLITOP_
{
	SGXTQ_FILTERTYPE	eFilter;
	IMG_UINT32			ui32ColourKey; /* In A8R8G8B8 format */
	IMG_UINT32			ui32ColourKeyMask;	/* In A8R8G8B8 format */
	IMG_BOOL			bEnableGamma;
	SGXTQ_COLOURKEY		eColourKey;
	SGXTQ_ROTATION		eRotation;
	SGXTQ_ALPHA			eAlpha;
	IMG_BYTE			byGlobalAlpha;
	IMG_BYTE			byCustomRop3;
#if defined(SUPPORT_DISPLAYCONTROLLER_TILING)
	IMG_UINT32 ui32BIFTile0Config;
#endif
	IMG_DEV_VIRTADDR	sUSEExecAddr;	/* Caller's pixel shader code, or NULL for default source copy blt */
	IMG_UINT32			UseParams[2];	/* Per-blt params used in above code */
	IMG_UINT32	 		uiNumTemporaryRegisters; /* Number of temporary registers that the pixel shader sUSEExecAddr uses */
	IMG_BOOL			bEnablePattern; /* Disable scaling, enable pattern wrapping, when source rect < dest rect */
    IMG_BOOL            bSingleSource;  /* It allows to use SINGLESOURCE texture in one TQ branch condition instead of forcing to use TWOSOURCE */
} SGXTQ_BLITOP;

typedef struct _SGXTQ_MIPGENOP_
{
	SGXTQ_FILTERTYPE	eFilter;
	IMG_UINT32			ui32Levels;
} SGXTQ_MIPGENOP;

typedef struct _SGXTQ_FILLOP_
{
	IMG_UINT32 ui32Colour;
	IMG_BYTE byCustomRop3;
#if defined(SUPPORT_DISPLAYCONTROLLER_TILING)
	IMG_UINT32 ui32BIFTile0Config;
#endif
} SGXTQ_FILLOP;

typedef struct _SGXTQ_BUFFERBLTOP_
{
	IMG_UINT32 ui32Bytes;
} SGXTQ_BUFFERBLTOP;

typedef struct _SGXTQ_CUSTOMOP_
{
	/*
		This type of custom operation specifies the USE and PDS address
	*/
	IMG_DEV_VIRTADDR	sDevVAddrUSECode;
	IMG_DEV_VIRTADDR	sDevVAddrPDSPrimCode;
	IMG_UINT32		ui32PDSPrimDataSize;
	IMG_DEV_VIRTADDR	sDevVAddrPDSSecCode;
	IMG_UINT32		ui32PDSSecDataSize;
	IMG_UINT32			ui32PDSSecNumAttr;

	/*
		This is the source render box (used for the vertex data)
		This must be supplied in pixels
	 */
	IMG_RECT sSrcBox;
	IMG_UINT32 ui32SrcWidth;
	IMG_UINT32 ui32SrcHeight;

	IMG_RECT sRenderBox;
	IMG_UINT32 aui32PBEState[6];

	IMG_BOOL bLoadFIRCoefficients;
	IMG_UINT32 ui32FIRHFilterTable;
	IMG_UINT32 ui32FIRHFilterLeft0;
	IMG_UINT32 ui32FIRHFilterRight0;
	IMG_UINT32 ui32FIRHFilterExtra0;
	IMG_UINT32 ui32FIRHFilterLeft1;
	IMG_UINT32 ui32FIRHFilterRight1;
	IMG_UINT32 ui32FIRHFilterExtra1;
	IMG_UINT32 ui32FIRHFilterLeft2;
	IMG_UINT32 ui32FIRHFilterRight2;
	IMG_UINT32 ui32FIRHFilterExtra2;
#if defined(SUPPORT_DISPLAYCONTROLLER_TILING)
	IMG_UINT32 ui32BIFTile0Config;
#endif

	IMG_UINT32			ui32NumPatches;
	PVRSRV_MEMUPDATE	asMemUpdates[SGX_MAX_TRANSFER_UPDATES];
} SGXTQ_CUSTOMOP;

typedef struct _SGXTQ_FULLCUSTOMOP_
{
	/*
		This type of custom blit specifies everything
	*/
	IMG_DEV_VIRTADDR	sDevVAddrVertexData; 
	IMG_UINT32 ui32StateSize;
	IMG_UINT32 ui32BIFBase;


	IMG_RECT sRenderBox;
	IMG_UINT32 aui32PBEState[6];

	IMG_UINT32 ui32ISPBgObjReg;
	IMG_UINT32 ui32ISPBgObjTagReg;
	IMG_UINT32 ui32ISPRenderReg;
	IMG_UINT32 ui32ISPRgnBaseReg;

	IMG_BOOL bLoadFIRCoefficients;
	IMG_UINT32 ui32FIRHFilterTable;
	IMG_UINT32 ui32FIRHFilterLeft0;
	IMG_UINT32 ui32FIRHFilterRight0;
	IMG_UINT32 ui32FIRHFilterExtra0;
	IMG_UINT32 ui32FIRHFilterLeft1;
	IMG_UINT32 ui32FIRHFilterRight1;
	IMG_UINT32 ui32FIRHFilterExtra1;
	IMG_UINT32 ui32FIRHFilterLeft2;
	IMG_UINT32 ui32FIRHFilterRight2;
	IMG_UINT32 ui32FIRHFilterExtra2;
#if defined(SUPPORT_DISPLAYCONTROLLER_TILING)
	IMG_UINT32 ui32BIFTile0Config;
#endif

	IMG_UINT32			ui32NumPatches;
	PVRSRV_MEMUPDATE	asMemUpdates[SGX_MAX_TRANSFER_UPDATES];
} SGXTQ_FULLCUSTOMOP;

typedef struct _SGXTQ_TEXTURE_UPLOADOP_ 
{
	IMG_PBYTE pbySrcLinAddr;
	IMG_UINT32 ui32BytesPP;
} SGXTQ_TEXTURE_UPLOADOP;

#if defined(SGX_FEATURE_2D_HARDWARE)
typedef struct __SGXTQ_2DBLITOP_
{
	IMG_UINT32	ui32CtrlSizeInDwords;
	IMG_UINT32	* pui32CtrlStream;
	IMG_UINT32  ui32AlphaRegValue;
	
} SGXTQ_2DBLITOP;
#endif

typedef struct _SGXTQ_CUSTOMSHADEROP_
{
	IMG_DEV_VIRTADDR	sUSEExecAddr;
	IMG_UINT32	 		ui32NumPAs;
	IMG_UINT32	 		ui32NumSAs;
	IMG_UINT32			UseParams[2];		// Per blt constants via secondaries
	IMG_UINT32	 		ui32NumTempRegs;

} SGXTQ_CUSTOMSHADEROP;

typedef struct _SGXTQ_COLOURLUTOP_
{
	PVRSRV_PIXEL_FORMAT	eLUTPxFmt;			// Not supported yet
	IMG_UINT32			ui32KeySizeInBits;	// LUT key size 8 bits -> 256 entries
	IMG_DEV_VIRTADDR	sLUTDevVAddr;
} SGXTQ_COLOURLUTOP;


/* Structures passed in as parameters to transfer queue functions */
typedef struct _SGX_TRANSFERCONTEXTCREATE_
{
	IMG_HANDLE				hDevMemContext;
} SGX_TRANSFERCONTEXTCREATE;

/* transfer queue flags */
#define SGX_KICKTRANSFER_FLAGS_TATQ_SYNC		0x00000001
#define SGX_KICKTRANSFER_FLAGS_3DTQ_SYNC		0x00000002
#define SGX_TRANSFER_FLAGS_INVERTX				0x00000004
#define SGX_TRANSFER_FLAGS_INVERTY				0x00000008

typedef struct _SGX_QUEUETRANSFER_
{
	IMG_UINT32		ui32Flags;
	SGXTQ_BLITTYPE eType; /* Type of transfer operation */

	union {
		SGXTQ_BLITOP sBlit;
		SGXTQ_MIPGENOP    sMipGen;
		SGXTQ_BUFFERBLTOP sBufBlt;
		SGXTQ_CUSTOMOP sCustom;
		SGXTQ_FULLCUSTOMOP sFullCustom;
		SGXTQ_FILLOP sFill;
		SGXTQ_TEXTURE_UPLOADOP sTextureUpload;
#if defined(SGX_FEATURE_2D_HARDWARE)
		SGXTQ_2DBLITOP	s2DBlit;	
#endif
		SGXTQ_CUSTOMSHADEROP sCustomShader;
		SGXTQ_COLOURLUTOP sColourLUT;
	} Details;

	IMG_UINT32		ui32NumSources;
	SGXTQ_SURFACE	asSources[SGXTQ_MAX_SURFACES];

	IMG_UINT32		ui32NumDest;
	SGXTQ_SURFACE	asDests[1];

	/* FIXME: move these into the surface structure, dropping src and dst prefix */
	IMG_UINT32		ui32NumSrcRects;
	IMG_RECT		asSrcRects[SGXTQ_MAX_RECTS];

	/* FIXME: move these into the surface structure, dropping src and dst prefix */
	IMG_UINT32		ui32NumDestRects;
	IMG_RECT		asDestRects[1];

#if defined(SGXTQ_PREP_SUBMIT_SEPERATE)
	IMG_HANDLE		*phTransferSubmit;
#endif

#if defined(PDUMP)
	IMG_UINT32			ui32PDumpFlags;
#endif

	IMG_UINT32			ui32NumStatusValues;
	PVRSRV_MEMUPDATE	asMemUpdates[SGX_MAX_TRANSFER_STATUS_VALS];
} SGX_QUEUETRANSFER;//FIXME: this name isn't great - change it to SGX_TRANSFER_OP

typedef struct _SGX_SUBMITTRANSFER_
{
	IMG_UINT32			ui32NumStatusValues;
	PVRSRV_MEMUPDATE	asMemUpdates[SGX_MAX_TRANSFER_STATUS_VALS];

	IMG_HANDLE hTransferSubmit;

#if defined(PDUMP)
	SGX_KICKTA_PDUMP	sTransferPDUMP;
	IMG_UINT32			ui32PDumpFlags;
#endif
} SGX_SUBMITTRANSFER;

#endif /* TRANSFER_QUEUE */


/******************************************************************************
 * device specific API prototypes
 *****************************************************************************/

/* returns SGX HW mappings for the client, e.g. CCB and CCBkicker */
IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXGetClientInfo(PVRSRV_DEV_DATA *psDevData,
										   PVRSRV_SGX_CLIENT_INFO *psSGXInfo);

IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXReleaseClientInfo(PVRSRV_DEV_DATA *psDevData,
											   PVRSRV_SGX_CLIENT_INFO *psSGXInfo);

IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXGetInternalDevInfo(const PVRSRV_DEV_DATA *psDevData,
												PVRSRV_SGX_INTERNALDEV_INFO *psSGXInternalDevInfo);


IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXScheduleProcessQueues(PVRSRV_DEV_DATA *psDevData);

IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXKickTA(PVRSRV_DEV_DATA			*psDevData,
									SGX_KICKTA				*psKickTA,
									SGX_KICKTA_OUTPUT *psKickTAOutput,
									IMG_PVOID				pvKickTAPDUMP,
									IMG_PVOID				pvKickSubmit);
#if defined(SGXTQ_PREP_SUBMIT_SEPERATE)
IMG_IMPORT 
PVRSRV_ERROR IMG_CALLCONV SGXKickSubmit (PVRSRV_DEV_DATA *psDevData,
									   IMG_PVOID psKickSubmit);
#endif


IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXCreateRenderContext(PVRSRV_DEV_DATA *psDevData,
												 PSGX_CREATERENDERCONTEXT psCreateRenderContext,
												 IMG_HANDLE *phRenderContext,
												 PPVRSRV_CLIENT_MEM_INFO *psVisTestResultMemInfo);

IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXDestroyRenderContext(PVRSRV_DEV_DATA *psDevData,
												  IMG_HANDLE hRenderContext,
												  PVRSRV_CLIENT_MEM_INFO *psVisTestResultMemInfo);

IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXAddRenderTarget(PVRSRV_DEV_DATA *psDevData,
											 SGX_ADDRENDTARG *psAddRTInfo,
											 IMG_HANDLE *phRTDataSet);

IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXRemoveRenderTarget(PVRSRV_DEV_DATA *psDevData,
												IMG_HANDLE hRenderContext,
												IMG_HANDLE hRTDataSet);

#if defined(SUPPORT_SGX_PRIORITY_SCHEDULING)
IMG_IMPORT
PVRSRV_ERROR SGXSetContextPriority(PVRSRV_DEV_DATA *psDevData,
									SGX_CONTEXT_PRIORITY *pePriority,
									IMG_HANDLE hRenderContext,
									IMG_HANDLE hTransferContext);
#endif /* #if defined(SUPPORT_SGX_PRIORITY_SCHEDULING) */

IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXGetPhysPageAddr(PVRSRV_DEV_DATA *psDevData,
											 IMG_HANDLE hDevMemHeap,
											 IMG_DEV_VIRTADDR sDevVAddr,
											 IMG_DEV_PHYADDR *pDevPAddr,
											 IMG_CPU_PHYADDR *pCpuPAddr);

/* FIXME: remove this API and associated code when SGX video is fully integrated */
IMG_IMPORT 
PVRSRV_ERROR IMG_CALLCONV SGXGetMMUPDAddr(PVRSRV_DEV_DATA	*psDevData,
										  IMG_HANDLE		hDevMemContext,
										  IMG_DEV_PHYADDR	*psPDDevPAddr);

IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXGetMiscInfo(PVRSRV_DEV_DATA *psDevData,
										 SGX_MISC_INFO *psData);

#if defined(TRANSFER_QUEUE)
IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXCreateTransferContext(PVRSRV_DEV_DATA *psDevData,
												   IMG_UINT32 ui32RequestedSBSize,
												   SGX_TRANSFERCONTEXTCREATE *psCreateTransfer,
												   IMG_HANDLE *phTransferContext);
#if defined(SUPPORT_KERNEL_SGXTQ)
IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXCreateSecondaryTransferContext(PVRSRV_DEV_DATA *psDevData,
															SGX_TRANSFERCONTEXTCREATE *psCreateTransfer,
															IMG_HANDLE  hMasterTransferContext,
															IMG_HANDLE *phTransferContext);
IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXDestroySecondaryTransferContext(IMG_HANDLE hTransferContext);
#endif
IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXDestroyTransferContext(IMG_HANDLE hTransferContext);

IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXQueueTransfer(IMG_HANDLE hTransferContext,
										  SGX_QUEUETRANSFER *psQueueTransfer);

#if defined(SGXTQ_PREP_SUBMIT_SEPERATE)
IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGXSubmitTransfer(IMG_HANDLE hTransferContext,
											SGX_SUBMITTRANSFER *psSubmitTransfer);
#endif
#endif /* TRANSFER_QUEUE */

IMG_IMPORT
PVRSRV_ERROR IMG_CALLCONV SGX2DQueryBlitsComplete(PVRSRV_DEV_DATA *psDevData,
												  PVRSRV_CLIENT_SYNC_INFO *psSyncInfo,
												  IMG_BOOL bWaitForComplete);

PVRSRV_ERROR SGX2DSyncEventReq(PVRSRV_DEV_DATA *psDevData,
				PVRSRV_CLIENT_SYNC_INFO *psSyncInfo,
				void *hUserData);

PVRSRV_ERROR SGX2DFlipEventReq(PVRSRV_DEV_DATA *psDevData,
				unsigned int overlay,
				void *hUserData);

PVRSRV_ERROR SGX2DUpdateEventReq(PVRSRV_DEV_DATA *psDevData,
				unsigned int overlay,
				void *hUserData);

#ifdef PDUMP
#define SGX_KICKTA_DUMPBITMAP_FLAGS_TWIDDLED		0x00000001
#define SGX_KICKTA_DUMPBITMAP_FLAGS_TILED			0x00000002
#endif

static inline void reset_render_state_bufs(struct render_state_buf_list *blist)
{
	blist->cnt = 0;
}

static inline void add_render_state_buf(struct render_state_buf_list *blist,
				enum render_state_buf_type type,
				PVRSRV_CLIENT_MEM_INFO *minfo,
				IMG_DEV_VIRTADDR addr, IMG_UINT32 size)
{
	struct render_state_buf_info *sb;

	if (blist->cnt >= IMG_ARRAY_SIZE(blist->info))
		return;

	sb = &blist->info[blist->cnt];
	blist->cnt++;
	sb->buf_id = (IMG_UINT32)minfo->hKernelMemInfo;
	sb->offset = addr.uiAddr - minfo->sDevVAddr.uiAddr;
	sb->type = type;
	sb->size = size;
}

static inline void copy_render_state_bufs(struct render_state_buf_list *dst,
				    struct render_state_buf_list *src)
{
	memcpy(dst->info, src->info, sizeof(src->info[0]) * src->cnt);
	dst->cnt = src->cnt;
}

#if defined (__cplusplus)
}
#endif

#endif /* __SGXAPI_H__ */

/******************************************************************************
 End of file (sgxapi.h)
******************************************************************************/
