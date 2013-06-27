/******************************************************************************
 * Name         : sgxerrata.h
 * Title        : SGX HW errata definitions
 *
 * Copyright    : 2005-2007 by Imagination Technologies Limited.
 *              : All rights reserved. No part of this software, either
 *              : material or conceptual may be copied or distributed,
 *              : transmitted, transcribed, stored in a retrieval system or
 *              : translated into any human or computer language in any form
 *              : by any means, electronic, mechanical, manual or otherwise,
 *              : or disclosed to third parties without the express written
 *              : permission of Imagination Technologies Limited,
 *              : Home Park Estate, Kings Langley, Hertfordshire,
 *              : WD4 8LZ, U.K.
 *
 * Platform     : ANSI
 *
 * Description  : Specifies associations between SGX core revisions
 *                and SW workarounds required to fix HW errata that exist
 *                in specific core revisions
 *
 * Modifications:-
 * $Log: sgxerrata.h $
 * 
 *  --- Revision Logs Removed --- 
 *****************************************************************************/
#ifndef _SGXERRATA_H_
#define _SGXERRATA_H_

/*
	For each SGX core revision specify which HW BRNs required SW workarounds
*/
#if defined(SGX520) && !defined(SGX_CORE_DEFINED)
	/* define the _current_ SGX520 RTL head revision */
	#define SGX_CORE_REV_HEAD	0
	#if defined(USE_SGX_CORE_REV_HEAD)
		/* build config selects Core Revision to be the Head */
		#define SGX_CORE_REV	SGX_CORE_REV_HEAD
	#endif

	#if SGX_CORE_REV == 100
		#define FIX_HW_BRN_20195/* Workaround in code */
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_23378/* Workaround in ucode */
		#define FIX_HW_BRN_23720/* Workaround in code (dx only) */
		#define FIX_HW_BRN_23761/* Workaround in code (dx, ogl, services) and ucode */
		#define FIX_HW_BRN_24281/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24637/* Workaround in OGL */
		#define FIX_HW_BRN_24895/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25060/* Workaround in useasm */
		#define FIX_HW_BRN_25077/* Workaround in code(ogles1/2). Not needed in ovg. */
		#define FIX_HW_BRN_25089/* Workaround in featuredefs and services */
		#define FIX_HW_BRN_25211/* Workaround in code */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC */
		#define FIX_HW_BRN_25892 /*Workaround in OpenVG*/   
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
		#define FIX_HW_BRN_28889/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == SGX_CORE_REV_HEAD
		/* RTL head - no BRNs to apply */
		#define FIX_HW_BRN_25892 /*Workaround in OpenVG*/   
	#else
		#error "sgxerrata.h: SGX520 Core Revision unspecified"	
	#endif
	#endif
	/* signal that the Core Version has a valid definition */
	#define SGX_CORE_DEFINED
#endif


#if defined(SGX530) && !defined(SGX_CORE_DEFINED)
	/* define the _current_ SGX530 RTL head revision */
	#define SGX_CORE_REV_HEAD	0
	#if defined(USE_SGX_CORE_REV_HEAD)
		/* build config selects Core Revision to be the Head */
		#define SGX_CORE_REV	SGX_CORE_REV_HEAD
	#endif

	#if SGX_CORE_REV == 103
		#define FIX_HW_BRN_20195/* Workaround in code */
		#define	FIX_HW_BRN_21039/* Workaround in code */
		#define	FIX_HW_BRN_21590/* Implicit Workaround in ukernel, driver ensures load/store TAAC and LSS serialised */
		#define FIX_HW_BRN_21697/* Workaround in USC/useasm */
		#define FIX_HW_BRN_21713/* Workaround in USC/useasm */
		#define FIX_HW_BRN_21735/* Workaround in ucode */
		#define FIX_HW_BRN_21752/* Workaround in USC/useasm */
		#define FIX_HW_BRN_21764/* No Feasible Workaround */
		#define FIX_HW_BRN_21784/* Workaround in USC/useasm */
		#define FIX_HW_BRN_21790/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_21797/* Workaround in code (ogles2) */
		#define FIX_HW_BRN_21842/* Workaround in ucode */
		#define FIX_HW_BRN_21893/* Workaround in ucode */
		#define FIX_HW_BRN_21934/* Workaround in code (ogles1/2, ovg) */
		#define FIX_HW_BRN_21986/* Workaround in code (ogles1/2, ovg) */
		#define FIX_HW_BRN_21992/* Implicit Workaround in services (srvclient), driver sets Y1=Y2=Y3 */
		#define FIX_HW_BRN_22010/* Implicit Workaround in ukernel  */
		#define FIX_HW_BRN_22014/* Workaround in ukernel  */
		#define FIX_HW_BRN_22015/* Implicit Workaround in code (ogles1/2, ogl) */
		#define FIX_HW_BRN_22020/* Implicit Workaround in code (ogles1/2, ovg, ogl) */
		#define FIX_HW_BRN_22021/* Implicit Workaround in ukernel, dont use 3D_TIMEOUT */
		#define FIX_HW_BRN_22030/* Workaround in code (featuredefs) */
		#define FIX_HW_BRN_22043/* Workaround in code */
		#define FIX_HW_BRN_22062/* Implicit Workaround in code (services, ukernel, ogles1/2, ogl) */
		#define FIX_HW_BRN_22100/* Workaround in code (dx only) */
		#define FIX_HW_BRN_22107/* Workaround in code */
		#define FIX_HW_BRN_22128/* Implicit Workaround in services (srvclient), vertex partitions always 4 */
		#define FIX_HW_BRN_22131/* Implicit Workaround in ukernel, PBE event never disabled. - commment added */
		#define FIX_HW_BRN_22136/* Workaround in USC/useasm */
		#define FIX_HW_BRN_22141/* Implicit Workaround in services (srvkm) written in SGXInitialise */
		#define FIX_HW_BRN_22166/* Implicit Workaround in ukernel, dont use PBE to write to memory */
		#define FIX_HW_BRN_22181/* Workaround in code (featuredefs) */
		#define FIX_HW_BRN_22249/* Workaround in code(TQ only) */
		#define FIX_HW_BRN_22279/* Workaround in code(dx only) */
		#define FIX_HW_BRN_22329/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_22336/* Workaround in code */
		#define FIX_HW_BRN_22364/* Workaround in DX code */
		#define FIX_HW_BRN_22364_152/* Workaround in ogles1/2, ogl */
		#define FIX_HW_BRN_22381/* Implicit Workaround in code (ogles1/2, ovg) */
		#define FIX_HW_BRN_22393/* Workaround in code (ogles1/2, ovg */
		#define FIX_HW_BRN_22412/* Workaround in ucode and code */
		#define FIX_HW_BRN_22419/* Workaround in code */
		#define FIX_HW_BRN_22427/* No Workaround possible (affects DX and OGL only) */
		#define FIX_HW_BRN_22489/* Implicit Workaround in code (ogl) */
		#define FIX_HW_BRN_22520/* Workaround in ukernel */
		#define FIX_HW_BRN_22563/* Workaround in services (srvkm) */
		#define FIX_HW_BRN_22584/* Workaround in services (srvinit) and ukernel */
		#define FIX_HW_BRN_22634/* Workaround controls multithreaded ukernel feature */
		#define FIX_HW_BRN_22666/* Workaround in DX only (RHW must be present) */
		#define FIX_HW_BRN_22737/* Workaround in ucode */
		#define FIX_HW_BRN_22837/* Implicit Workaround in services (srvclient) - commment added */
		#define FIX_HW_BRN_22852/* Implicit Workaround in code */
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_23062/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23070/* Workaround in services */
		#define FIX_HW_BRN_23164/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23194/* Workaround in code */
		#define FIX_HW_BRN_23228/* Implicit Workaround in ukernel, ogles1/2, ovg (dont use) */
		#define FIX_HW_BRN_23259/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23331/* Implicit Workaround in ogles1/2, ovg (never set loadmask) */
		#define FIX_HW_BRN_23378/* Workaround in ucode */
		#define FIX_HW_BRN_23461/* Workaround in useasm */
		#define FIX_HW_BRN_23533/* Implicit Workaround in ukernel (SPM Mode 0 specific) */
		#define FIX_HW_BRN_23620/* Implicit Workaround in ogles1/2, ovg (send accum object or clear), need patching in ukernel. */
		#define FIX_HW_BRN_23632/* Workaround in code(services) */
		#define FIX_HW_BRN_23677/* Workaround in ucode */
		#define FIX_HW_BRN_23720/* Workaround in code (dx only) */
		#define FIX_HW_BRN_23761/* Workaround in code (dx, ogl, services) and ucode */
		#define FIX_HW_BRN_23765/* Workaround in code (services) */
		#define FIX_HW_BRN_23815/* Workaround in code (dx, occlusion query specific) */
		#define FIX_HW_BRN_23861/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23862/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23870/* Workaround in ucode */
		#define FIX_HW_BRN_23896/* Implicit Workaround in code (ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23946/* Workaround in code (ogl, ogles1/2) */
		#define FIX_HW_BRN_23960/* Workaround in useasm */
		#define FIX_HW_BRN_23971/* Workaround in code(dx only), MTE boundingbox and ISP vistest related */
		#define FIX_HW_BRN_24181/* Workaround in code(ogles1/2) */
		#define FIX_HW_BRN_24281/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24304/* Workaround in ucode */
		#define FIX_HW_BRN_24549/* Workaround in ucode */
		#define FIX_HW_BRN_24637/* Workaround in OGL */
		#define FIX_HW_BRN_24895/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25060/* Workaround in useasm */
		#define FIX_HW_BRN_25077/* Workaround in code(ogles1/2). Not needed in ovg. */
		#define FIX_HW_BRN_25089/* Workaround in featuredefs and services */
		#define FIX_HW_BRN_25211/* Workaround in code */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26922/* Workaround in code */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
		#define FIX_HW_BRN_27408/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_28889/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == 110
		#define FIX_HW_BRN_21590/* Implicit Workaround in ukernel, driver ensures load/store TAAC and LSS serialised */
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_23062/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23070/* Workaround in services*/
		#define FIX_HW_BRN_23164/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23194/* Workaround in code */
		#define FIX_HW_BRN_23228/* Implicit Workaround in ukernel, ogles1/2, ovg (dont use) */
		#define FIX_HW_BRN_23259/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23331/* Implicit Workaround in ogles1/2, ovg (never set loadmask) */
		#define FIX_HW_BRN_23378/* Workaround in ucode */
		#define FIX_HW_BRN_23461/* Workaround in useasm */
		#define FIX_HW_BRN_23533/* Implicit Workaround in ukernel (SPM Mode 0 specific) */
		#define FIX_HW_BRN_23620/* Implicit Workaround in ogles1/2, ovg (send accum object or clear), need patching in ukernel. */
		#define FIX_HW_BRN_23632/* Workaround in code(services) */
		#define FIX_HW_BRN_23677/* Workaround in ucode */
		#define FIX_HW_BRN_23720/* Workaround in code (dx only) */
		#define FIX_HW_BRN_23761/* Workaround in code (dx, ogl, services) and ucode */
		#define FIX_HW_BRN_23765/* Workaround in code (services) */
		#define FIX_HW_BRN_23815/* Workaround in code (dx, occlusion query specific) */
		#define FIX_HW_BRN_23861/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23862/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23870/* Workaround in ucode */
		#define FIX_HW_BRN_23896/* Implicit Workaround in code (ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23946/* Workaround in code (ogl, ogles1/2) */
		#define FIX_HW_BRN_23960/* Workaround in useasm */
		#define FIX_HW_BRN_23971/* Workaround in code(dx only), MTE boundingbox and ISP vistest related */
		#define FIX_HW_BRN_24181/* Workaround in code(ogles1/2) */
		#define FIX_HW_BRN_24281/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24304/* Workaround in ucode */
		#define FIX_HW_BRN_24549/* Workaround in ucode */		
		#define FIX_HW_BRN_24637/* Workaround in OGL */
		#define FIX_HW_BRN_24895/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25060/* Workaround in useasm */
		#define FIX_HW_BRN_25077/* Workaround in code(ogles1/2). Not needed in ovg. */
		#define FIX_HW_BRN_25089/* Workaround in featuredefs and services */
		#define FIX_HW_BRN_25211/* Workaround in code */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26922/* Workaround in code */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
		#define FIX_HW_BRN_27408/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_28889/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == 111
		#define FIX_HW_BRN_21590/* Implicit Workaround in ukernel, driver ensures load/store TAAC and LSS serialised */
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_23062/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23070/* Workaround in services*/
		#define FIX_HW_BRN_23164/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23194/* Workaround in code */
		#define FIX_HW_BRN_23228/* Implicit Workaround in ukernel, ogles1/2, ovg (dont use) */
		#define FIX_HW_BRN_23259/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23331/* Implicit Workaround in ogles1/2, ovg (never set loadmask) */
		#define FIX_HW_BRN_23378/* Workaround in ucode */
		#define FIX_HW_BRN_23461/* Workaround in useasm */
		#define FIX_HW_BRN_23533/* Implicit Workaround in ukernel (SPM Mode 0 specific) */
		#define FIX_HW_BRN_23620/* Implicit Workaround in ogles1/2, ovg (send accum object or clear), need patching in ukernel. */
		#define FIX_HW_BRN_23632/* Workaround in code(services) */
		#define FIX_HW_BRN_23677/* Workaround in ucode */
		#define FIX_HW_BRN_23720/* Workaround in code (dx only) */
		#define FIX_HW_BRN_23761/* Workaround in code (dx, ogl, services) and ucode */
		#define FIX_HW_BRN_23815/* Workaround in code (dx, occlusion query specific) */
		#define FIX_HW_BRN_23861/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23862/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23870/* Workaround in ucode */
		#define FIX_HW_BRN_23896/* Implicit Workaround in code (ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23946/* Workaround in code (ogl, ogles1/2) */
		#define FIX_HW_BRN_23960/* Workaround in useasm */
		#define FIX_HW_BRN_23971/* Workaround in code(dx only), MTE boundingbox and ISP vistest related */
		#define FIX_HW_BRN_24181/* Workaround in code(ogles1/2) */
		#define FIX_HW_BRN_24281/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24304/* Workaround in ucode */
		#define FIX_HW_BRN_24549/* Workaround in ucode */		
		#define FIX_HW_BRN_24637/* Workaround in OGL */
		#define FIX_HW_BRN_24895/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25060/* Workaround in useasm */
		#define FIX_HW_BRN_25077/* Workaround in code(ogles1/2). Not needed in ovg. */
		#define FIX_HW_BRN_25089/* Workaround in featuredefs and services */
		#define FIX_HW_BRN_25211/* Workaround in code */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26922/* Workaround in code */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
		#define FIX_HW_BRN_27408/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_28889/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == 1111
		#define FIX_HW_BRN_21590/* Implicit Workaround in ukernel, driver ensures load/store TAAC and LSS serialised */
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_23062/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23070/* Workaround in services*/
		#define FIX_HW_BRN_23164/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23194/* Workaround in code */
		#define FIX_HW_BRN_23228/* Implicit Workaround in ukernel, ogles1/2, ovg (dont use) */
		#define FIX_HW_BRN_23259/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23331/* Implicit Workaround in ogles1/2, ovg (never set loadmask) */
		#define FIX_HW_BRN_23378/* Workaround in ucode */
		#define FIX_HW_BRN_23461/* Workaround in useasm */
		#define FIX_HW_BRN_23533/* Implicit Workaround in ukernel (SPM Mode 0 specific) */
		#define FIX_HW_BRN_23620/* Implicit Workaround in ogles1/2, ovg (send accum object or clear), need patching in ukernel. */
		#define FIX_HW_BRN_23632/* Workaround in code(services) */
		#define FIX_HW_BRN_23677/* Workaround in ucode */
		#define FIX_HW_BRN_23720/* Workaround in code (dx only) */
		#define FIX_HW_BRN_23761/* Workaround in code (dx, ogl, services) and ucode */
		#define FIX_HW_BRN_23815/* Workaround in code (dx, occlusion query specific) */
		#define FIX_HW_BRN_23861/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23862/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23870/* Workaround in ucode */
		#define FIX_HW_BRN_23896/* Implicit Workaround in code (ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23946/* Workaround in code (ogl, ogles1/2) */
		#define FIX_HW_BRN_23960/* Workaround in useasm */
		#define FIX_HW_BRN_23971/* Workaround in code(dx only), MTE boundingbox and ISP vistest related */
		#define FIX_HW_BRN_24181/* Workaround in code(ogles1/2) */
		#define FIX_HW_BRN_24281/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24304/* Workaround in ucode */
		#define FIX_HW_BRN_24549/* Workaround in ucode */		
		#define FIX_HW_BRN_24637/* Workaround in OGL */
		#define FIX_HW_BRN_24895/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25060/* Workaround in useasm */
		#define FIX_HW_BRN_25077/* Workaround in code(ogles1/2). Not needed in ovg. */
		#define FIX_HW_BRN_25089/* Workaround in featuredefs and services */
		#define FIX_HW_BRN_25211/* Workaround in code */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26922/* Workaround in code */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
		#define FIX_HW_BRN_27408/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_28889/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == 120
		#define FIX_HW_BRN_21590/* Implicit Workaround in ukernel, driver ensures load/store TAAC and LSS serialised */
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel */
		#define FIX_HW_BRN_23259/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23620/* Implicit Workaround in ogles1/2, ovg (send accum object or clear), need patching in ukernel. */
		#define FIX_HW_BRN_23632/* Workaround in code(services) */
		#define FIX_HW_BRN_23720/* Workaround in code (dx only) */
		#define FIX_HW_BRN_23761/* Workaround in code (dx, ogl, services) and ucode */
		#define FIX_HW_BRN_23815/* Workaround in code (dx, occlusion query specific) */
		#define FIX_HW_BRN_23861/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_24181/* Workaround in code(ogles1/2) */
		#define FIX_HW_BRN_24281/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24549/* Workaround in ucode */		
		#define FIX_HW_BRN_24637/* Workaround in OGL */
		#define FIX_HW_BRN_24895/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25060/* Workaround in useasm */
		#define FIX_HW_BRN_25077/* Workaround in code(ogles1/2). Not needed in ovg. */
		#define FIX_HW_BRN_25089/* Workaround in featuredefs and services */
		#define FIX_HW_BRN_25211/* Workaround in code */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26922/* Workaround in code */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
		#define FIX_HW_BRN_27408/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_28889/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == 121
		#define FIX_HW_BRN_21590/* Implicit Workaround in ukernel, driver ensures load/store TAAC and LSS serialised */
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel */
		#define FIX_HW_BRN_23259/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23620/* Implicit Workaround in ogles1/2, ovg (send accum object or clear), need patching in ukernel. */
		#define FIX_HW_BRN_23632/* Workaround in code(services) */
		#define FIX_HW_BRN_23720/* Workaround in code (dx only) */
		#define FIX_HW_BRN_23761/* Workaround in code (dx, ogl, services) and ucode */
		#define FIX_HW_BRN_23815/* Workaround in code (dx, occlusion query specific) */
		#define FIX_HW_BRN_23861/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_24181/* Workaround in code(ogles1/2) */
		#define FIX_HW_BRN_24281/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24549/* Workaround in ucode */
		#define FIX_HW_BRN_24637/* Workaround in OGL */
		#define FIX_HW_BRN_24895/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25060/* Workaround in useasm */
		#define FIX_HW_BRN_25077/* Workaround in code(ogles1/2). Not needed in ovg. */
		#define FIX_HW_BRN_25089/* Workaround in featuredefs and services */
		#define FIX_HW_BRN_25211/* Workaround in code */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26922/* Workaround in code */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
		#define FIX_HW_BRN_27408/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_28889/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == 125
		#define FIX_HW_BRN_21590/* Implicit Workaround in ukernel, driver ensures load/store TAAC and LSS serialised */
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel */
		#define FIX_HW_BRN_23259/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23620/* Implicit Workaround in ogles1/2, ovg (send accum object or clear), need patching in ukernel. */
		#define FIX_HW_BRN_23632/* Workaround in code(services) */
		#define FIX_HW_BRN_23720/* Workaround in code (dx only) */
		#define FIX_HW_BRN_23761/* Workaround in code (dx, ogl, services) and ucode */
		#define FIX_HW_BRN_23815/* Workaround in code (dx, occlusion query specific) */
		#define FIX_HW_BRN_23861/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_24181/* Workaround in code(ogles1/2) */
		#define FIX_HW_BRN_24281/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24549/* Workaround in ucode */
		#define FIX_HW_BRN_24637/* Workaround in OGL */
		#define FIX_HW_BRN_24895/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25060/* Workaround in useasm */
		#define FIX_HW_BRN_25077/* Workaround in code(ogles1/2). Not needed in ovg. */
		#define FIX_HW_BRN_25089/* Workaround in featuredefs and services */
		#define FIX_HW_BRN_25211/* Workaround in code */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26922/* Workaround in code */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
		#define FIX_HW_BRN_27408/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_28889/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == SGX_CORE_REV_HEAD
		/* RTL head */
		#define FIX_HW_BRN_23080/* Workaround in code (codegen, dx) */
	#else
		#error "sgxerrata.h: SGX530 Core Revision unspecified"
	#endif
	#endif
	#endif
	#endif
	#endif
	#endif
	#endif
	#endif
	/* signal that the Core Version has a valid definition */
	#define SGX_CORE_DEFINED
#endif


#if defined(SGX531) && !defined(SGX_CORE_DEFINED)
	/* define the _current_ SGX531 RTL head revision */
	#define SGX_CORE_REV_HEAD	0
	#if defined(USE_SGX_CORE_REV_HEAD)
		/* build config selects Core Revision to be the Head */
		#define SGX_CORE_REV	SGX_CORE_REV_HEAD
	#endif
	
	#if SGX_CORE_REV == 101
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_26361/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_26518/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26620/* Workaround in services (srvkm) */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
		#define FIX_HW_BRN_27408/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_27723/* Workaround in usc */
	#else
	#if SGX_CORE_REV == SGX_CORE_REV_HEAD
		/* RTL head - no BRNs to apply */
	#else
		#error "sgxerrata.h: SGX531 Core Revision unspecified"	
	#endif
	#endif
	/* signal that the Core Version has a valid definition */
	#define SGX_CORE_DEFINED
#endif


#if (defined(SGX535) || defined(SGX535_V1_1)) && !defined(SGX_CORE_DEFINED)
	/* define the _current_ SGX535 RTL head revision */
	#define SGX_CORE_REV_HEAD	0
	#if defined(USE_SGX_CORE_REV_HEAD)
		/* build config selects Core Revision to be the Head */
		#define SGX_CORE_REV	SGX_CORE_REV_HEAD
	#endif

	#if SGX_CORE_REV == 111			
		#define FIX_HW_BRN_20195/* Workaround in code */
		#define FIX_HW_BRN_21934/* Workaround in code (ogles1/2, ovg) */
		#define FIX_HW_BRN_21992/* Implicit Workaround in services (srvclient), driver sets Y1=Y2=Y3 */
		#define FIX_HW_BRN_22067/* Workaround in code (featuredefs) */
		#define FIX_HW_BRN_22100/* Workaround in code (dx only) */
		#define FIX_HW_BRN_22107/* Workaround in code */
		#define FIX_HW_BRN_22111/* Workaround in code(dx only) */
		#define FIX_HW_BRN_22128/* Implicit Workaround in services (srvclient), vertex partitions always 4 */
		#define FIX_HW_BRN_22131/* Implicit Workaround in ukernel, PBE event never disabled. - commment added */
		#define FIX_HW_BRN_22136/* Workaround in USC/useasm */
		#define FIX_HW_BRN_22141/* Implicit Workaround in services (srvkm) written in SGXInitialise */
		#define FIX_HW_BRN_22162/* Workaround in code(dx only) */
		#define FIX_HW_BRN_22199/* Workaround in code (dx only), control F16 texture filtering */
		#define FIX_HW_BRN_22248/* No feasible workaround possible */		
		#define FIX_HW_BRN_22304/* Workaround in code (dx only), control F16 texture filtering */
		#define FIX_HW_BRN_22329/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_22336/* Workaround in code */
		#define FIX_HW_BRN_22364/* Workaround in DX code */
		#define FIX_HW_BRN_22364_153/* Workaround in code (ogles1/2, ogl) */
		#define FIX_HW_BRN_22371/* Implicit workaround in code (services) */
		#define FIX_HW_BRN_22381/* Implicit Workaround in code (ogles1/2, ovg) */
		#define FIX_HW_BRN_22391/* Workaround in code (slow PT) */
		#define FIX_HW_BRN_22412/* Workaround in ucode and code */
		#define FIX_HW_BRN_22419/* Workaround in code */
		#define FIX_HW_BRN_22427/* No Workaround possible (affects DX and OGL only) */		
		#define FIX_HW_BRN_22489/* Implicit Workaround in code (ogl) */
		#define FIX_HW_BRN_22563/* Workaround in services (srvkm) */
		#define FIX_HW_BRN_22610/* Workaround in code (services) */
		#define FIX_HW_BRN_22634/* Workaround controls multithreaded ukernel feature */
		#define FIX_HW_BRN_22648/* Workaround in code (clockgating) */
		#define FIX_HW_BRN_22656/* Workaround in code (services) */
		#define FIX_HW_BRN_22657/* Implicit Workaround, no overlapped DPM */
		#define FIX_HW_BRN_22666/* Workaround in DX only (RHW must be present) */
		#define FIX_HW_BRN_22693/* Workaround in code (featuredefs) */
		#define FIX_HW_BRN_22694/* Workaround in code (pvr2d) */
		#define FIX_HW_BRN_22837/* Implicit Workaround in services (srvclient) - commment added */
		#define FIX_HW_BRN_22849/* Workaround in code (services) */
		#define FIX_HW_BRN_22852/* Implicit Workaround in code */
		#define FIX_HW_BRN_22997/* Workaround in code and ucode */
		#define FIX_HW_BRN_23020/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23030/* Workaround in code */
		#define FIX_HW_BRN_23054/* Workaround in code (featuredefs) */
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_23062/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23070/* Workaround in services */
		#define FIX_HW_BRN_23080/* Workaround in code (codegen, dx) */
		#define FIX_HW_BRN_23137/* Implicit Workaround in code (dx) */
		#define FIX_HW_BRN_23141/* Workaround in code(services) */
		#define FIX_HW_BRN_23155/* Implicit Workaround in code */
		#define FIX_HW_BRN_23164/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23194/* Workaround in code */
		#define FIX_HW_BRN_23228/* Implicit Workaround in ukernel, ogles1/2, ovg (dont use) */
		#define FIX_HW_BRN_23258/* Workaround in code(services) + ucode */
		#define FIX_HW_BRN_23259/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23281/* Workaround in services code, note: not in 530 */
		#define FIX_HW_BRN_23331/* Implicit Workaround in code (microkernel, ogles1,2, ogl2) */
		#define FIX_HW_BRN_23353/* Implicit Workaround (services) */
		#define FIX_HW_BRN_23378/* Workaround in ucode */
		#define FIX_HW_BRN_23410/* Workaround in code (services) and ucode */
		#define FIX_HW_BRN_23460/* Workaround in code(codegen, ogles1/2, ovg, dx, services) */
		#define FIX_HW_BRN_23461/* Workaround in useasm */
		#define FIX_HW_BRN_23533/* Implicit Workaround in ukernel (SPM Mode 0 specific) */
		#define FIX_HW_BRN_23615/* Implicit Workaround in code (microkernel, ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23620/* Implicit Workaround in code (ogles1,2, ovg) */
		#define FIX_HW_BRN_23632/* Workaround in code(services) */
		#define FIX_HW_BRN_23677/* Workaround in ucode */
		#define FIX_HW_BRN_23687/* Workaround in code(ogles1, ogles2, ovg, dx) */
		#define FIX_HW_BRN_23690/* Workaround in code(ogles1, ogles2, ovg, dx) */
		#define FIX_HW_BRN_23720/* Workaround in code (dx only) */
		#define FIX_HW_BRN_23761/* Workaround in code (dx, ogl, services) and ucode */
		#define FIX_HW_BRN_23765/* Workaround in code (services) */
		#define FIX_HW_BRN_23775/* Implicit Workaround in code */
		#define FIX_HW_BRN_23815/* Workaround in code (dx, occlusion query specific) */
		#define FIX_HW_BRN_23861/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23862/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23870/* Workaround in ucode */
		#define FIX_HW_BRN_23896/* Implicit Workaround in code (ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23949/* Workaround in code(codegen, ogles1/2, ovg, dx, services) */
		#define FIX_HW_BRN_23960/* Workaround in useasm */
		#define FIX_HW_BRN_23971/* Workaround in code(dx only), MTE boundingbox and ISP vistest related */
		#define FIX_HW_BRN_24181/* Workaround in code(ogles1/2) */
		#define FIX_HW_BRN_24281/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24304/* Workaround in ucode */
		#define FIX_HW_BRN_24435/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24637/* Workaround in OGL */
		#define FIX_HW_BRN_24895/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25060/* Workaround in useasm */
		#define FIX_HW_BRN_25077/* Workaround in code(ogles1/2). Not needed in ovg. */
		#define FIX_HW_BRN_25089/* Workaround in featuredefs and services */
		#define FIX_HW_BRN_25211/* Workaround in code */
		#define FIX_HW_BRN_25355/* Check in useasm */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC */
		#define FIX_HW_BRN_25910/* Workaround in ucode */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26711/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == 1111/* 'modified' 111 */
		#define FIX_HW_BRN_20195/* Workaround in code */
		#define FIX_HW_BRN_21934/* Workaround in code (ogles1/2, ovg) */
		#define FIX_HW_BRN_21992/* Implicit Workaround in services (srvclient), driver sets Y1=Y2=Y3 */
		#define FIX_HW_BRN_22067/* Workaround in code (featuredefs) */
		#define FIX_HW_BRN_22100/* Workaround in code (dx only) */
		#define FIX_HW_BRN_22107/* Workaround in code */
		#define FIX_HW_BRN_22111/* Workaround in code(dx only) */
		#define FIX_HW_BRN_22128/* Implicit Workaround in services (srvclient), vertex partitions always 4 */
		#define FIX_HW_BRN_22131/* Implicit Workaround in ukernel, PBE event never disabled. - commment added */
		#define FIX_HW_BRN_22136/* Workaround in USC/useasm */
		#define FIX_HW_BRN_22141/* Implicit Workaround in services (srvkm) written in SGXInitialise. */
		#define FIX_HW_BRN_22162/* Workaround in code(dx only) */
		#define FIX_HW_BRN_22199/* Workaround in code (dx only), control F16 texture filtering */
		#define FIX_HW_BRN_22247/* workaround in code (ukernel), breakpoint objects not used */
		#define FIX_HW_BRN_22248/* No feasible workaround possible */
		#define FIX_HW_BRN_22287/* Workaround in code (oglcompiler only) */
		#define FIX_HW_BRN_22304/* Workaround in code (dx only), control F16 texture filtering */
		#define FIX_HW_BRN_22329/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_22336/* Workaround in code */
		#define FIX_HW_BRN_22364/* Workaround in DX code */
		#define FIX_HW_BRN_22364_153/* Workaround in code (ogles1/2, ogl) */
		#define FIX_HW_BRN_22371/* Implicit workaround in code (services) */
		#define FIX_HW_BRN_22380/* Workaround in code (autogating feature) */
		#define FIX_HW_BRN_22381/* Implicit Workaround in code (ogles1/2, ovg) */
		#define FIX_HW_BRN_22391/* Workaround in code (slow PT) */
		#define FIX_HW_BRN_22393/* Workaround in code (ogles1/2, ovg */
		#define FIX_HW_BRN_22412/* Workaround in ucode and code */
		#define FIX_HW_BRN_22419/* Workaround in code */
		#define FIX_HW_BRN_22427/* No Workaround possible (affects DX and OGL only) */		
		#define FIX_HW_BRN_22489/* Implicit Workaround in code (ogl) */
		#define FIX_HW_BRN_22563/* Workaround in services (srvkm) */
		#define FIX_HW_BRN_22610/* Workaround in code (services) */
		#define FIX_HW_BRN_22634/* Workaround controls multithreaded ukernel feature */
		#define FIX_HW_BRN_22648/* Workaround in code (clockgating) */
		#define FIX_HW_BRN_22656/* Workaround in code (services) */
		#define FIX_HW_BRN_22657/* Implicit Workaround, no overlapped DPM */
		#define FIX_HW_BRN_22666/* Workaround in DX only (RHW must be present) */
		#define FIX_HW_BRN_22693/* Workaround in code (featuredefs) */
		#define FIX_HW_BRN_22694/* Workaround in code (pvr2d) */
		#define FIX_HW_BRN_22837/* Implicit Workaround in services (srvclient) - commment added */
		#define FIX_HW_BRN_22849/* Workaround in code (services) */
		#define FIX_HW_BRN_22852/* Implicit Workaround in code */		
		#define FIX_HW_BRN_22997/* Workaround in code and ucode */
		#define FIX_HW_BRN_23020/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23030/* Workaround in code */
		#define FIX_HW_BRN_23054/* Workaround in code (featuredefs) */
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_23062/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23080/* Workaround in code (codegen, dx) */
		#define FIX_HW_BRN_23137/* Implicit Workaround in code (affects dx only) */
		#define FIX_HW_BRN_23141/* Workaround in code(services) */
		#define FIX_HW_BRN_23155/* Implicit Workaround in code */		
		#define FIX_HW_BRN_23164/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23194/* Workaround in code */
		#define FIX_HW_BRN_23228/* Implicit Workaround in ukernel, ogles1/2, ovg (dont use) */
		#define FIX_HW_BRN_23258/* Workaround in code(services) + ucode */
		#define FIX_HW_BRN_23259/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23281/* Workaround in services code, note: not in 530 */
		#define FIX_HW_BRN_23331/* Implicit Workaround in code (microkernel, ogles1,2, ogl2) */
		#define FIX_HW_BRN_23353/* Implicit Workaround (services) */
		#define FIX_HW_BRN_23378/* Workaround in ucode */
		#define FIX_HW_BRN_23410/* Workaround in code (services) and ucode */
		#define FIX_HW_BRN_23460/* Workaround in code(codegen, ogles1/2, ovg, dx, services) */
		#define FIX_HW_BRN_23461/* Workaround in useasm */
		#define FIX_HW_BRN_23533/* Implicit Workaround in ukernel (SPM Mode 0 specific) */
		#define FIX_HW_BRN_23615/* Implicit Workaround in code (microkernel, ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23620/* Implicit Workaround in code (ogles1,2, ovg) */
		#define FIX_HW_BRN_23632/* Workaround in code(services) */
		#define FIX_HW_BRN_23677/* Workaround in ucode */
		#define FIX_HW_BRN_23687/* Workaround in code(ogles1, ogles2, ovg, dx) */
		#define FIX_HW_BRN_23690/* Workaround in code(ogles1, ogles2, ovg, dx) */
		#define FIX_HW_BRN_23720/* Workaround in code (dx only) */
		#define FIX_HW_BRN_23761/* Workaround in code (dx, ogl, services) and ucode */
		#define FIX_HW_BRN_23765/* Workaround in code (services) */
		#define FIX_HW_BRN_23775/* Implicit Workaround in code */		
		#define FIX_HW_BRN_23815/* Workaround in code (dx, occlusion query specific)	 */
		#define FIX_HW_BRN_23861/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23862/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23870/* Workaround in ucode */
		#define FIX_HW_BRN_23896/* Implicit Workaround in code (ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23949/* Workaround in code(codegen, ogles1/2, ovg, dx, services) */
		#define FIX_HW_BRN_23960/* Workaround in useasm */
		#define FIX_HW_BRN_23971/* Workaround in code(dx only), MTE boundingbox and ISP vistest related */
		#define FIX_HW_BRN_24181/* Workaround in code(ogles1/2) */
		#define FIX_HW_BRN_24281/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24304/* Workaround in ucode */
		#define FIX_HW_BRN_24435/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24637/* Workaround in OGL */
		#define FIX_HW_BRN_24895/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25060/* Workaround in useasm */
		#define FIX_HW_BRN_25077/* Workaround in code(ogles1/2). Not needed in ovg. */
		#define FIX_HW_BRN_25089/* Workaround in featuredefs and services */
		#define FIX_HW_BRN_25211/* Workaround in code */
		#define FIX_HW_BRN_25355/* Check in useasm */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC */
		#define FIX_HW_BRN_25910/* Workaround in ucode */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26711/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == 112
		#define FIX_HW_BRN_20195/* Workaround in code */
		#define FIX_HW_BRN_22111/* Workaround in code(dx only) */
		#define FIX_HW_BRN_22141/* Implicit Workaround in services (srvkm) written in SGXInitialise */
		#define FIX_HW_BRN_22419/* Workaround in code */
		#define FIX_HW_BRN_22563/* Workaround in services (srvkm) */
		#define FIX_HW_BRN_22610/* Workaround in code (services) */
		#define FIX_HW_BRN_22634/* Workaround controls multithreaded ukernel feature */
		#define FIX_HW_BRN_22648/* Workaround in code (clockgating) */
		#define FIX_HW_BRN_22656/* Workaround in code (services) */
		#define FIX_HW_BRN_22666/* Workaround in DX only (RHW must be present) */
		#define FIX_HW_BRN_22693/* Workaround in code (featuredefs) */
		#define FIX_HW_BRN_22694/* Workaround in code (pvr2d) */
		#define FIX_HW_BRN_22837/* Implicit Workaround in services (srvclient) - commment added */
		#define FIX_HW_BRN_22849/* Workaround in code (services) */
		#define FIX_HW_BRN_22852/* Implicit Workaround in code */		
		#define FIX_HW_BRN_22997/* Workaround in code and ucode */
		#define FIX_HW_BRN_23020/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23030/* Workaround in code */
		#define FIX_HW_BRN_23054/* Workaround in code (featuredefs) */
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_23062/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23080/* Workaround in code (codegen, dx) */
		#define FIX_HW_BRN_23137/* Implicit Workaround in code (dx) */		
		#define FIX_HW_BRN_23141/* Workaround in code(services) */
		#define FIX_HW_BRN_23155/* Implicit Workaround in code */		
		#define FIX_HW_BRN_23164/* Workaround in USC/useasm */
		#define FIX_HW_BRN_23194/* Workaround in code */
		#define FIX_HW_BRN_23228/* Implicit Workaround in ukernel, ogles1/2, ovg (dont use) */
		#define FIX_HW_BRN_23258/* Workaround in code(services) + ucode */
		#define FIX_HW_BRN_23259/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23281/* Workaround in services code, note: not in 530 */
		#define FIX_HW_BRN_23331/* Implicit Workaround in code (microkernel, ogles1,2, ogl2) */
		#define FIX_HW_BRN_23353/* Implicit Workaround (services) */
		#define FIX_HW_BRN_23378/* Workaround in ucode */
		#define FIX_HW_BRN_23410/* Workaround in code (services) and ucode */
		#define FIX_HW_BRN_23460/* Workaround in code(codegen, ogles1/2, ovg, dx, services) */
		#define FIX_HW_BRN_23461/* Workaround in useasm */
		#define FIX_HW_BRN_23533/* Implicit Workaround in ukernel (SPM Mode 0 specific) */
		#define FIX_HW_BRN_23615/* Implicit Workaround in code (microkernel, ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23620/* Implicit Workaround in code (ogles1,2, ovg) */
		#define FIX_HW_BRN_23677/* Workaround in ucode */
		#define FIX_HW_BRN_23687/* Workaround in code(ogles1, ogles2, ovg, dx) */
		#define FIX_HW_BRN_23690/* Workaround in code(ogles1, ogles2, ovg, dx) */
		#define FIX_HW_BRN_23720/* Workaround in code (dx only) */
		#define FIX_HW_BRN_23761/* Workaround in code (dx, ogl, services) and ucode */
		#define FIX_HW_BRN_23765/* Workaround in code (services) */
		#define FIX_HW_BRN_23775/* Implicit Workaround in code */		
		#define FIX_HW_BRN_23815/* Workaround in code (dx, occlusion query specific) */
		#define FIX_HW_BRN_23861/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23862/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23870/* Workaround in ucode */
		#define FIX_HW_BRN_23896/* Implicit Workaround in code (ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23949/* Workaround in code(codegen, ogles1/2, ovg, dx, services) */
		#define FIX_HW_BRN_23960/* Workaround in useasm */
		#define FIX_HW_BRN_23971/* Workaround in code(dx only), MTE boundingbox and ISP vistest related */
		#define FIX_HW_BRN_24181/* Workaround in code(ogles1/2) */
		#define FIX_HW_BRN_24281/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24304/* Workaround in ucode */
		#define FIX_HW_BRN_24435/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24637/* Workaround in OGL */
		#define FIX_HW_BRN_24895/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25060/* Workaround in useasm */
		#define FIX_HW_BRN_25077/* Workaround in code(ogles1/2). Not needed in ovg. */
		#define FIX_HW_BRN_25089/* Workaround in featuredefs and services */
		#define FIX_HW_BRN_25355/* Check in useasm */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC */
		#define FIX_HW_BRN_25910/* Workaround in ucode */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26711/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == 113
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_23070/* Workaround in services */
		#define FIX_HW_BRN_23080/* Workaround in code (codegen, dx) */
		#define FIX_HW_BRN_23194/* Workaround in code */
		#define FIX_HW_BRN_23228/* Implicit Workaround in ukernel, ogles1/2, ovg (dont use) */
		#define FIX_HW_BRN_23258/* Workaround in code(services) + ucode */
		#define FIX_HW_BRN_23259/* Workaround in code (ogles1/2, ovg, dx) */
		#define FIX_HW_BRN_23281/* Workaround in services code, note: not in 530 */
		#define FIX_HW_BRN_23331/* Implicit Workaround in code (microkernel, ogles1,2, ogl2) */
		#define FIX_HW_BRN_23353/* Implicit Workaround (services) */
		#define FIX_HW_BRN_23378/* Workaround in ucode */
		#define FIX_HW_BRN_23410/* Workaround in code (services) and ucode */
		#define FIX_HW_BRN_23460/* Workaround in code(codegen, ogles1/2, ovg, dx, services) */
		#define FIX_HW_BRN_23461/* Workaround in useasm */
		#define FIX_HW_BRN_23533/* Implicit Workaround in ukernel (SPM Mode 0 specific) */
		#define FIX_HW_BRN_23615/* Implicit Workaround in code (microkernel, ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23620/* Implicit Workaround in code (ogles1,2, ovg) */
		#define FIX_HW_BRN_23632/* Workaround in code(services) */
		#define	FIX_HW_BRN_23677/* Workaround in ucode */
		#define FIX_HW_BRN_23687/* Workaround in code(ogles1, ogles2, ovg, dx) */
		#define FIX_HW_BRN_23690/* Workaround in code(ogles1, ogles2, ovg, dx) */
		#define FIX_HW_BRN_23720/* Workaround in code (dx only) */
		#define FIX_HW_BRN_23761/* Workaround in code (dx, ogl, services) and ucode */
		#define FIX_HW_BRN_23765/* Workaround in code (services) */
		#define FIX_HW_BRN_23775/* Implicit Workaround in code */				
		#define FIX_HW_BRN_23815/* Workaround in code (dx, occlusion query specific) */
		#define FIX_HW_BRN_23861/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23862/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23870/* Workaround in ucode */
		#define FIX_HW_BRN_23896/* Implicit Workaround in code (ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23944/* Workaround in code (services) */
		#define FIX_HW_BRN_23949/* Workaround in code(codegen, ogles1/2, ovg, dx, services) */
		#define FIX_HW_BRN_23971/* Workaround in code(dx only), MTE boundingbox and ISP vistest related */
		#define FIX_HW_BRN_24181/* Workaround in code(ogles1/2) */
		#define FIX_HW_BRN_24281/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24304/* Workaround in ucode */
		#define FIX_HW_BRN_24435/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24637/* Workaround in OGL */
		#define FIX_HW_BRN_24895/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25060/* Workaround in useasm */
		#define FIX_HW_BRN_25077/* Workaround in code(ogles1/2). Not needed in ovg. */
		#define FIX_HW_BRN_25089/* Workaround in featuredefs and services */
		#define FIX_HW_BRN_25211/* Workaround in code */
		#define FIX_HW_BRN_25355/* Check in useasm */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC */
		#define FIX_HW_BRN_25910/* Workaround in ucode */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26711/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == 121
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_23080/* Workaround in code (codegen, dx) */
		#define FIX_HW_BRN_23259/* Workaround in code (dx9) */
		#define FIX_HW_BRN_23410/* Workaround in code (services) and ucode */
		#define FIX_HW_BRN_23533/* Implicit Workaround in ukernel (SPM Mode 0 specific) */
		#define FIX_HW_BRN_23615/* Implicit Workaround in code (microkernel, ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23620/* Implicit Workaround in code (ogles1,2, ovg) */
		#define FIX_HW_BRN_23632/* Workaround in code(services) */
		#define FIX_HW_BRN_23677/* Workaround in ucode */
		#define FIX_HW_BRN_23687/* Workaround in code(ogles1, ogles2, ovg, dx) */
		#define FIX_HW_BRN_23690/* Workaround in code(ogles1, ogles2, ovg, dx) */
		#define FIX_HW_BRN_23720/* Workaround in code (dx only) */
		#define FIX_HW_BRN_23761/* Workaround in code (dx, ogl, services) and ucode */
		#define FIX_HW_BRN_23775/* Implicit Workaround in code */		
		#define FIX_HW_BRN_23815/* Workaround in code (dx, occlusion query specific) */
		#define FIX_HW_BRN_23861/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23862/* Workaround in code (services) + ucode */
		#define FIX_HW_BRN_23870/* Workaround in ucode */
		#define FIX_HW_BRN_23896/* Implicit Workaround in code (ogles1,2, ovg, ogl2) */
		#define FIX_HW_BRN_23944/* Workaround in code (services) */
		#define FIX_HW_BRN_23960/* Workaround in useasm */
		#define FIX_HW_BRN_23971/* Workaround in code(dx only), MTE boundingbox and ISP vistest related */
		#define FIX_HW_BRN_24181/* Workaround in code(ogles1/2) */
		#define FIX_HW_BRN_24281/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24304/* Workaround in ucode */
		#define FIX_HW_BRN_24435/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_24637/* Workaround in OGL */
		#define FIX_HW_BRN_24895/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25077/* Workaround in code(ogles1/2). Not needed in ovg. */
		#define FIX_HW_BRN_25089/* Workaround in featuredefs and services */
		#define FIX_HW_BRN_25211/* Workaround in code */
		#define FIX_HW_BRN_25355/* Check in useasm */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC */
		#define FIX_HW_BRN_25910/* Workaround in ucode */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26711/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == SGX_CORE_REV_HEAD
		/* RTL head */
		#define FIX_HW_BRN_23080/* Workaround in code (codegen, dx) */
	#else
		#error "sgxerrata.h: SGX535 Core Revision unspecified"
	#endif
	#endif
	#endif
	#endif
	#endif
	#endif
	/* signal that the Core Version has a valid definition */
	#define SGX_CORE_DEFINED
#endif


#if defined(SGX540) && !defined(SGX_CORE_DEFINED)
	/* define the _current_ SGX540 RTL head revision */
	#define SGX_CORE_REV_HEAD	0
	#if defined(USE_SGX_CORE_REV_HEAD)
		/* build config selects Core Revision to be the Head */
		#define SGX_CORE_REV	SGX_CORE_REV_HEAD
	#endif

	#if SGX_CORE_REV == 101
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_25161/* Workaround in client drivers */
		#define FIX_HW_BRN_25339/* Workaround in all pds code */
		#define FIX_HW_BRN_25503/* Workaround in code (services) */
		#define FIX_HW_BRN_25580/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25582/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25615/* Workaround in ucode */
		#define FIX_HW_BRN_25659/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26202/* Workaround in code (services) */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26361/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_26518/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_26620/* Workaround in services (srvkm) */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
		#define FIX_HW_BRN_27408/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_27723/* Workaround in usc */
	#else
	#if SGX_CORE_REV == 110
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_25161/* Workaround in client drivers */
		#define FIX_HW_BRN_25339/* Workaround in all pds code */
		#define FIX_HW_BRN_25503/* Workaround in code (services) */
		#define FIX_HW_BRN_25659/* Workaround in ucode */
		#define FIX_HW_BRN_25804/* Workaround in USC/useasm */
		#define FIX_HW_BRN_25941/* Workaround double pixel emit multi-dm bug */
		#define FIX_HW_BRN_26202/* Workaround in code (services) */
		#define FIX_HW_BRN_26246/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_26361/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_26518/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_26620/* Workaround in services (srvkm) */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
		#define FIX_HW_BRN_27408/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_27723/* Workaround in usc */
	#else
	#if SGX_CORE_REV == 120
		#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
		#define FIX_HW_BRN_27408/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_27723/* Workaround in usc */
	#else
	#if SGX_CORE_REV == 121
		#define FIX_HW_BRN_27723/* Workaround in usc */
	#else
	#if SGX_CORE_REV == 125
		#define FIX_HW_BRN_27723/* Workaround in usc */
	#else
	#if SGX_CORE_REV == SGX_CORE_REV_HEAD
		/* RTL head - no BRNs to apply */
	#else
		#error "sgxerrata.h: SGX540 Core Revision unspecified"
	#endif
	#endif
	#endif
	#endif
	#endif
	#endif
	/* signal that the Core Version has a valid definition */
	#define SGX_CORE_DEFINED	
#endif


#if defined(SGX541) && !defined(SGX_CORE_DEFINED)
	#if defined(SGX_FEATURE_MP)
		/* define the _current_ SGX541 MP RTL head revision */
		#define SGX_CORE_REV_HEAD	0
		#if defined(USE_SGX_CORE_REV_HEAD)
			/* build config selects Core Revision to be the Head */
			#define SGX_CORE_REV	SGX_CORE_REV_HEAD
		#endif
	
		#if SGX_CORE_REV == 100
			#define FIX_HW_BRN_23055/* Workaround in services (srvclient) and uKernel. */
			#define FIX_HW_BRN_27723/* Workaround in usc */
		#else
		#if SGX_CORE_REV == 101
			#define FIX_HW_BRN_27723/* Workaround in usc */
		#else
			#if SGX_CORE_REV == SGX_CORE_REV_HEAD
				/* RTL head - no BRNs to apply */
			#else
				#error "sgxerrata.h: SGX541 MP Core Revision unspecified"
			#endif
		#endif
		#endif
		/* signal that the Core Version has a valid definition */
		#define SGX_CORE_DEFINED
	#else /* SGX_FEATURE_MP */
		/* define the _current_ SGX541 RTL head revision */
		#define SGX_CORE_REV_HEAD	0
		#if defined(USE_SGX_CORE_REV_HEAD)
			/* build config selects Core Revision to be the Head */
			#define SGX_CORE_REV	SGX_CORE_REV_HEAD
		#endif
	
		#if SGX_CORE_REV == 100
			/* add BRNs here */
		#else
		#if SGX_CORE_REV == SGX_CORE_REV_HEAD
			/* RTL head - no BRNs to apply */
		#else
			#error "sgxerrata.h: SGX541 Core Revision unspecified"
		#endif
		#endif
		/* signal that the Core Version has a valid definition */
		#define SGX_CORE_DEFINED	
	#endif /* SGX_FEATURE_MP */
#endif


#if defined(SGX543) && !defined(SGX_CORE_DEFINED)
	/* define the _current_ SGX543 MP RTL head revision */
	#define SGX_CORE_REV_HEAD	0
	#if defined(USE_SGX_CORE_REV_HEAD)
		/* build config selects Core Revision to be the Head */
		#define SGX_CORE_REV	SGX_CORE_REV_HEAD
	#endif

	#if SGX_CORE_REV == 100
		/* add BRNs here */
	#else
		#if SGX_CORE_REV == SGX_CORE_REV_HEAD
			/* RTL head - no BRNs to apply */
		#else
			#error "sgxerrata.h: SGX543 Core Revision unspecified"
		#endif
	#endif
	/* signal that the Core Version has a valid definition */
	#define SGX_CORE_DEFINED
#endif


#if defined(SGX545) && !defined(SGX_CORE_DEFINED)
	/* define the _current_ SGX545 RTL head revision */
	#define SGX_CORE_REV_HEAD	0
	#if defined(USE_SGX_CORE_REV_HEAD)
		/* build config selects Core Revision to be the Head */
		#define SGX_CORE_REV	SGX_CORE_REV_HEAD
	#endif

	#if SGX_CORE_REV == 107
		#define FIX_HW_BRN_26336/* Workaround vertex DM pixel emits */
		#define FIX_HW_BRN_26361/* Workaround in services (srvclient) */
		#define FIX_HW_BRN_26620/* Workaround in services (srvkm) */
		#define FIX_HW_BRN_26656/* Workaround in sgx featuredefs */
		#define FIX_HW_BRN_27251/* Workaround in ucode */
	#else
	#if SGX_CORE_REV == SGX_CORE_REV_HEAD
		/* RTL head - no BRNs to apply */
	#else
		#error "sgxerrata.h: SGX545 Core Revision unspecified"
	#endif
	#endif
	/* signal that the Core Version has a valid definition */
	#define SGX_CORE_DEFINED
#endif

#if !defined(SGX_CORE_DEFINED)
	//FIXME: change message to error when USC build resolved
	//#error "sgxerrata.h: SGX Core Version unspecified"
#if defined (__GNUC__)
	#warning "sgxerrata.h: SGX Core Version unspecified"
#else
	#pragma message("sgxerrata.h: SGX Core Version unspecified")	
#endif
#endif

/*
	Code including this file can request a table mapping core IDs to
	the errata that affect them so they can support multiple
	cores in one binary.
*/
#if defined(INCLUDE_SGX_BUG_TABLE)

#include "img_types.h"

#include "sgxcoretypes.h"

#define SGX_BUG_FLAGS_FIX_HW_BRN_21697				(0x00000001)
#define SGX_BUG_FLAGS_FIX_HW_BRN_21713				(0x00000002)
#define SGX_BUG_FLAGS_FIX_HW_BRN_21784				(0x00000004)
#define SGX_BUG_FLAGS_FIX_HW_BRN_22136				(0x00000008)
#define SGX_BUG_FLAGS_FIX_HW_BRN_21752				(0x00000010)
#define SGX_BUG_FLAGS_FIX_HW_BRN_23062				(0x00000020)
#define SGX_BUG_FLAGS_FIX_HW_BRN_23164				(0x00000040)
#define SGX_BUG_FLAGS_FIX_HW_BRN_23461				(0x00000080)
#define SGX_BUG_FLAGS_FIX_HW_BRN_23960				(0x00000100)
#define SGX_BUG_FLAGS_FIX_HW_BRN_24895				(0x00000200)
#define SGX_BUG_FLAGS_FIX_HW_BRN_25060				(0x00000400)
#define SGX_BUG_FLAGS_FIX_HW_BRN_25355				(0x00000800)
#define SGX_BUG_FLAGS_FIX_HW_BRN_25804				(0x00001000)
#define SGX_BUG_FLAGS_FIX_HW_BRN_25580				(0x00002000)
#define SGX_BUG_FLAGS_FIX_HW_BRN_25582				(0x00004000)
#define SGX_BUG_FLAGS_FIX_HW_BRN_26570				(0x00008000)
#define SGX_BUG_FLAGS_FIX_HW_BRN_26681				(0x00010000)
#define SGX_BUG_FLAGS_FIX_HW_BRN_27235				(0x00040000)
#define SGX_BUG_FLAGS_FIX_HW_BRN_27723				(0x00080000)				

#endif /* defined(INCLUDE_SGX_BUG_TABLE) */

#endif /* _SGXERRATA_H_ */

/******************************************************************************
 End of file (sgxerrata.h)
******************************************************************************/
