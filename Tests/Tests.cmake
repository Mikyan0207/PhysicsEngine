set(TESTS_ROOT ${REPOSITORY_ROOT}/Tests)

set(TESTS_SOURCE_FILES
  ${TESTS_ROOT}/doctest.h
  ${TESTS_ROOT}/Math/Vector2Tests.cpp
  ${TESTS_ROOT}/Math/Vector3Tests.cpp
  ${TESTS_ROOT}/Math/Vector4Tests.cpp
  ${TESTS_ROOT}/Math/Mat2x2Tests.cpp
  ${TESTS_ROOT}/Math/Mat3x3Tests.cpp
  ${TESTS_ROOT}/Tests.cpp
  ${TESTS_ROOT}/Tests.h
  ${TESTS_ROOT}/Tests.cmake)

source_group(TREE ${TESTS_ROOT} FILES ${TESTS_SOURCE_FILES})
