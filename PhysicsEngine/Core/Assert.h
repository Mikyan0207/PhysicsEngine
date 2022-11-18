#pragma once

#include <cstdint>

PE_NAMESPACE_BEGIN

#if defined(_DEBUG) && !defined(PE_ENABLE_ASSERTS)
#define PE_ENABLE_ASSERTS
#endif

#ifdef PE_ENABLE_ASSERTS

using AssertFailedFunction = bool (*)(const char* expression, const char* message, const char* file,
                                      std::uint32_t line);

extern AssertFailedFunction AssertFailed;

struct AssertLastParam
{
};

inline bool AssertFailedParamHelper(const char* expression, const char* file, std::uint32_t line, AssertLastParam)
{
    return AssertFailed(expression, nullptr, file, line);
}

inline bool AssertFailedParamHelper(const char* expression, const char* file, std::uint32_t line, const char* message,
                                    AssertLastParam)
{
    return AssertFailed(expression, message, file, line);
}

#define PE_ASSERT(Expression, ...)                                                                                     \
    do                                                                                                                 \
    {                                                                                                                  \
        if (!(Expression) &&                                                                                           \
            AssertFailedParamHelper(#Expression, __FILE__, std::uint32_t(__LINE__), ##__VA_ARGS__, AssertLastParam())) \
            PE_BREAKPOINT;                                                                                             \
    } while (false)

#define PE_IF_ENABLE_ASSERTS(...) __VA_ARGS__

#else

#define PE_ASSERT(...) ((void)0)

#define PE_IF_ENABLE_ASSERTS(...)

#endif

PE_NAMESPACE_END
