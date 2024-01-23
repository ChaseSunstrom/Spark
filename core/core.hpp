#ifndef CORE_CORE_H
#define CORE_CORE_H

#define __A_CORE_API__
#define __A_CORE_TEST__

//#define __A_CORE_DEBUG__

#define __A_CORE_TRACE__
#define __A_CORE_INFO__
#define __A_CORE_WARN__
#define __A_CORE_ERROR__

#include "std_include.hpp"
#include "types.hpp"

#ifdef _MSC_VER
	#define __A_CORE_INLINE__   __forceinline
	#define __A_CORE_RESTRICT__ __restrict 
	#pragma warning(disable : 4996)
#else
	#define __A_CORE_INLINE__   inline
	#define __A_CORE_RESTRICT__ restrict
#endif // _MSC_VER

#endif // CORE_CORE_H