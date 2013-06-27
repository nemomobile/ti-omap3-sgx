/******************************************************************************
* Name         : pvr_debug.h
* Title        : PVR Debug Declarations
* Author       : J R Morrissey
* Created      : 20 May 2002
*
* Copyright    : 2002-2008 by Imagination Technologies Limited.
*                All rights reserved. No part of this software, either
*                material or conceptual may be copied or distributed,
*                transmitted, transcribed, stored in a retrieval system
*                or translated into any human or computer language in any
*                form by any means, electronic, mechanical, manual or
*                otherwise, or disclosed to third parties without the
*                express written permission of
*                Imagination Technologies Limited, Home Park Estate,
*                Kings Langley, Hertfordshire, WD4 8LZ, U.K.
*
* Description  : Provides debug functionality
*
* Platform     : Generic
*
* Modifications:-
* $Log: pvr_debug.h $
******************************************************************************/

#ifndef __PVR_DEBUG_H__
#define __PVR_DEBUG_H__


#include "img_types.h"

#if defined (__cplusplus)
extern "C" {
#endif

#define PVR_MAX_DEBUG_MESSAGE_LEN	(512)

/* These are privately used by pvr_debug, use the PVR_DBG_ defines instead */
#define DBGPRIV_FATAL		0x01UL
#define DBGPRIV_ERROR		0x02UL
#define DBGPRIV_WARNING		0x04UL
#define DBGPRIV_MESSAGE		0x08UL
#define DBGPRIV_VERBOSE		0x10UL
#define DBGPRIV_CALLTRACE	0x20UL
#define DBGPRIV_ALLOC		0x40UL
#define DBGPRIV_ALLLEVELS	(DBGPRIV_FATAL | DBGPRIV_ERROR | DBGPRIV_WARNING | DBGPRIV_MESSAGE | DBGPRIV_VERBOSE)



#define PVR_DBG_FATAL		DBGPRIV_FATAL,__FILE__, __LINE__
#define PVR_DBG_ERROR		DBGPRIV_ERROR,__FILE__, __LINE__
#define PVR_DBG_WARNING		DBGPRIV_WARNING,__FILE__, __LINE__
#define PVR_DBG_MESSAGE		DBGPRIV_MESSAGE,__FILE__, __LINE__
#define PVR_DBG_VERBOSE		DBGPRIV_VERBOSE,__FILE__, __LINE__
#define PVR_DBG_CALLTRACE	DBGPRIV_CALLTRACE,__FILE__, __LINE__
#define PVR_DBG_ALLOC		DBGPRIV_ALLOC,__FILE__, __LINE__

#if defined(DEBUG)
	#define PVR_ASSERT(EXPR) if (!(EXPR)) PVRSRVDebugAssertFail(__FILE__, __LINE__);	/* PRQA S 845,3614 */
	#define PVR_DPF(X)		PVRSRVDebugPrintf X
	#define PVR_TRACE(X)	PVRSRVTrace X

IMG_IMPORT IMG_VOID IMG_CALLCONV PVRSRVDebugAssertFail(const IMG_CHAR *pszFile,
									IMG_UINT32 ui32Line);

IMG_IMPORT IMG_VOID IMG_CALLCONV PVRSRVDebugPrintf(IMG_UINT32 ui32DebugLevel,
									const IMG_CHAR *pszFileName,
									IMG_UINT32 ui32Line,
									const IMG_CHAR *pszFormat,
									...);

IMG_IMPORT IMG_VOID IMG_CALLCONV PVRSRVTrace(const IMG_CHAR* pszFormat, ... );

IMG_VOID PVRSRVDebugSetLevel (IMG_UINT32 uDebugLevel);

		#define PVR_DBG_BREAK

#else

#if defined(TIMING)

	#define PVR_ASSERT(EXPR)
	#define PVR_DPF(X)
	#define PVR_TRACE(X)	PVRSRVTrace X
	#define PVR_DBG_BREAK

IMG_IMPORT IMG_VOID IMG_CALLCONV PVRSRVTrace(const IMG_CHAR* pszFormat, ... );

#else
	/* fix as PVR_ASSERT IS defined during QAC analysis */
	#define PVR_ASSERT(EXPR)	/* PRQA S 845,3614 */
	#define PVR_DPF(X)
	#define PVR_TRACE(X)
	#define PVR_DBG_BREAK

#endif /* TIMING */
#endif /* DEBUG */


#if defined (__cplusplus)
}
#endif

#endif	/* __PVR_DEBUG_H__ */

/******************************************************************************
 End of file (pvr_debug.h)
******************************************************************************/

