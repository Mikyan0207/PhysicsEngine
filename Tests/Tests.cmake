set(TESTS_ROOT ${REPOSITORY_ROOT}/Tests)

set(TESTS_SOURCE_FILES
  ${TESTS_ROOT}/doctest.h
  ${TESTS_ROOT}/Math/Vector2Tests.cpp
  ${TESTS_ROOT}/Tests.cpp
  ${TESTS_ROOT}/Tests.h)

source_group(TREE ${TESTS_ROOT} FILES ${TESTS_SOURCE_FILES})
