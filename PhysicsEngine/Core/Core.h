#pragma once

#if defined(__clang__)
#define PE_COMPILER_CLANG
#elif defined(__GNUC__)
#define PE_COMPILER_GCC
#elif defined(_MSC_VER)
#define PE_COMPILER_MSVC
#endif

#if defined(PE_COMPILER_CLANG) || defined(PE_COMPILER_GCC)
#define PE_INLINE __inline__ __attribute__((always_inline))
#elif defined(PE_COMPILER_MSVC)
#define PE_INLINE __forceinline
#else
#error Undefined
#endif

#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)
#define PE_VECTOR_ALIGNMENT 16
#endif


// Pragmas to store / restore the warning state and to disable individual warnings
#ifdef PE_COMPILER_CLANG
#define PE_PRAGMA(x)					_Pragma(#x)
#define PE_SUPPRESS_WARNING_PUSH		PE_PRAGMA(clang diagnostic push)
#define PE_SUPPRESS_WARNING_POP		PE_PRAGMA(clang diagnostic pop)
#define PE_CLANG_SUPPRESS_WARNING(w)	PE_PRAGMA(clang diagnostic ignored w)
#else
#define PE_CLANG_SUPPRESS_WARNING(w)
#endif
#ifdef PE_COMPILER_GCC
#define PE_PRAGMA(x)					_Pragma(#x)
#define PE_SUPPRESS_WARNING_PUSH		PE_PRAGMA(GCC diagnostic push)
#define PE_SUPPRESS_WARNING_POP		PE_PRAGMA(GCC diagnostic pop)
#define PE_GCC_SUPPRESS_WARNING(w)		PE_PRAGMA(GCC diagnostic ignored w)
#else
#define PE_GCC_SUPPRESS_WARNING(w)
#endif
#ifdef PE_COMPILER_MSVC
#define PE_PRAGMA(x)					__pragma(x)
#define PE_SUPPRESS_WARNING_PUSH		PE_PRAGMA(warning (push))
#define PE_SUPPRESS_WARNING_POP		PE_PRAGMA(warning (pop))
#define PE_MSVC_SUPPRESS_WARNING(w)	PE_PRAGMA(warning (disable : w))
#else
#define PE_MSVC_SUPPRESS_WARNING(w)
#endif

// Disable common warnings triggered by the Physics Engine when compiling with -Wall
#define PE_SUPPRESS_WARNINGS																	\
	PE_CLANG_SUPPRESS_WARNING("-Wc++98-compat")												    \
	PE_CLANG_SUPPRESS_WARNING("-Wc++98-compat-pedantic")										\
	PE_CLANG_SUPPRESS_WARNING("-Wfloat-equal")													\
	PE_CLANG_SUPPRESS_WARNING("-Wsign-conversion")												\
	PE_CLANG_SUPPRESS_WARNING("-Wold-style-cast")												\
	PE_CLANG_SUPPRESS_WARNING("-Wgnu-anonymous-struct")										    \
	PE_CLANG_SUPPRESS_WARNING("-Wnested-anon-types")											\
	PE_CLANG_SUPPRESS_WARNING("-Wglobal-constructors")											\
	PE_CLANG_SUPPRESS_WARNING("-Wexit-time-destructors")										\
	PE_CLANG_SUPPRESS_WARNING("-Wnonportable-system-include-path")								\
	PE_CLANG_SUPPRESS_WARNING("-Wlanguage-extension-token")									    \
	PE_CLANG_SUPPRESS_WARNING("-Wunused-parameter")											    \
	PE_CLANG_SUPPRESS_WARNING("-Wformat-nonliteral")											\
	PE_CLANG_SUPPRESS_WARNING("-Wcovered-switch-default")										\
	PE_CLANG_SUPPRESS_WARNING("-Wcast-align")													\
	PE_CLANG_SUPPRESS_WARNING("-Winvalid-offsetof")											    \
	PE_CLANG_SUPPRESS_WARNING("-Wgnu-zero-variadic-macro-arguments")							\
	PE_CLANG_SUPPRESS_WARNING("-Wdocumentation-unknown-command")								\
	PE_CLANG_SUPPRESS_WARNING("-Wctad-maybe-unsupported")										\
	PE_CLANG_SUPPRESS_WARNING("-Wdeprecated-copy")												\
	PE_CLANG_SUPPRESS_WARNING("-Wimplicit-int-float-conversion")                			    \
																								\
	PE_GCC_SUPPRESS_WARNING("-Wcomment")														\
	PE_GCC_SUPPRESS_WARNING("-Winvalid-offsetof")												\
	PE_GCC_SUPPRESS_WARNING("-Wclass-memaccess")												\


// Begin the PE namespace
#define PE_NAMESPACE_BEGIN																		\
	PE_SUPPRESS_WARNING_PUSH																	\
	PE_SUPPRESS_WARNINGS																		\
	namespace Physics {

// End the PE namespace
#define PE_NAMESPACE_END																		\
	}																							\
	PE_SUPPRESS_WARNING_POP
