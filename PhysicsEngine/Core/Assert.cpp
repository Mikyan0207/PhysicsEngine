#include <PhysicsEngine/Core/Assert.hpp>
#include <PhysicsEngine/PhysicsEngine.hpp>

PE_SUPPRESS_WARNINGS_STD_BEGIN
#include <fstream>
PE_SUPPRESS_WARNINGS_STD_END

PE_NAMESPACE_BEGIN

static void DummyTrace([[maybe_unused]] const char* fmt, ...)
{
    PE_ASSERT(false);
};

TraceFunction Trace = DummyTrace;

#ifdef PE_ENABLE_ASSERTS

static bool DummyAssertFailed(const char* expression, const char* message, const char* file, std::uint32_t line)
{
    return true; // Trigger breakpoint
};

AssertFailedFunction AssertFailed = DummyAssertFailed;

#endif

PE_NAMESPACE_END
