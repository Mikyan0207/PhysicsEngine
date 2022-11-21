#include <PhysicsEngine/PhysicsEngine.h>

#ifdef PE_PLATFORM_WINDOWS
#include <crtdbg.h>
#endif

#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_NO_WINDOWS_SEH

PE_SUPPRESS_WARNINGS_STD_BEGIN
#include "doctest.h"
PE_SUPPRESS_WARNINGS_STD_END

using namespace Physics;
using namespace doctest;

PE_SUPPRESS_WARNINGS

int main(int argc, char* argv[])
{
#ifdef _DEBUG
	// Enable leak detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	Context().run();

	system("pause");

	return 0;
}
