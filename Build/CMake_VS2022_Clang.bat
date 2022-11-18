@echo off
echo:
echo -------------------------------------------------------
echo - C++ Clang for Windows v12.0.0+ is required.
echo - C++ Clang-CL v143+ Build Tools (x64/x86) is required.
echo -------------------------------------------------------
cmake -S . -B VS2022_Clang -G "Visual Studio 17 2022" -A x64 -T ClangCL
echo Open VS2022_Clang/PhysicsEngine to build the project.
