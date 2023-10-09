set(PHYSICS_ENGINE_ROOT ${REPOSITORY_ROOT}/PhysicsEngine)

set(SOURCE_FILES
    ${PHYSICS_ENGINE_ROOT}/PhysicsEngine.hpp
    ${PHYSICS_ENGINE_ROOT}/Core/Core.hpp
    ${PHYSICS_ENGINE_ROOT}/Core/Assert.cpp
    ${PHYSICS_ENGINE_ROOT}/Core/Assert.hpp
    ${PHYSICS_ENGINE_ROOT}/Math/Math.hpp
    ${PHYSICS_ENGINE_ROOT}/Math/Types.hpp
    ${PHYSICS_ENGINE_ROOT}/Math/Float2.hpp
    ${PHYSICS_ENGINE_ROOT}/Math/Float3.hpp
    ${PHYSICS_ENGINE_ROOT}/Math/Vector4.hpp
    ${PHYSICS_ENGINE_ROOT}/Math/Vector4.inl
    ${PHYSICS_ENGINE_ROOT}/Math/Vector3.inl
    ${PHYSICS_ENGINE_ROOT}/Math/Vector3.hpp
    ${PHYSICS_ENGINE_ROOT}/Math/Vector2.hpp
    ${PHYSICS_ENGINE_ROOT}/Math/Vector2.inl
    ${PHYSICS_ENGINE_ROOT}/Math/Mat4x4.hpp
    ${PHYSICS_ENGINE_ROOT}/Math/Mat4x4.inl
	${PHYSICS_ENGINE_ROOT}/Math/Mat3x3.hpp
    ${PHYSICS_ENGINE_ROOT}/Math/Mat3x3.inl
    ${PHYSICS_ENGINE_ROOT}/Math/Mat2x2.hpp
    ${PHYSICS_ENGINE_ROOT}/Math/Mat2x2.inl
    ${PHYSICS_ENGINE_ROOT}/Engine.cmake)

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	# Add natvis file
  #set(SOURCE_FILES ${SOURCE_FILES} ${PHYSICS_ENGINE_ROOT}/PhysicsEngine.natvis)
endif()

source_group(TREE ${PHYSICS_ENGINE_ROOT} FILES ${SOURCE_FILES})

add_library(PhysicsEngine STATIC ${SOURCE_FILES})
target_include_directories(PhysicsEngine PUBLIC ${REPOSITORY_ROOT})

# TODO(Mikyan): Configs
