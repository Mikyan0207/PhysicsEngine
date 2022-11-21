set(PHYSICS_ENGINE_ROOT ${REPOSITORY_ROOT}/PhysicsEngine)

set(SOURCE_FILES
    ${PHYSICS_ENGINE_ROOT}/PhysicsEngine.h
    ${PHYSICS_ENGINE_ROOT}/Core/Core.h
    ${PHYSICS_ENGINE_ROOT}/Core/Assert.cpp
    ${PHYSICS_ENGINE_ROOT}/Core/Assert.h
    ${PHYSICS_ENGINE_ROOT}/Math/Math.h
    ${PHYSICS_ENGINE_ROOT}/Math/Types.h
    ${PHYSICS_ENGINE_ROOT}/Math/Float2.h
    ${PHYSICS_ENGINE_ROOT}/Math/Float3.h
    ${PHYSICS_ENGINE_ROOT}/Math/Vector4.h
    ${PHYSICS_ENGINE_ROOT}/Math/Vector4.cpp
    ${PHYSICS_ENGINE_ROOT}/Math/Vector4.inl
    ${PHYSICS_ENGINE_ROOT}/Math/Vector3.cpp
    ${PHYSICS_ENGINE_ROOT}/Math/Vector3.inl
    ${PHYSICS_ENGINE_ROOT}/Math/Vector3.h
    ${PHYSICS_ENGINE_ROOT}/Math/Vector2.h
    ${PHYSICS_ENGINE_ROOT}/Math/Vector2.inl
    ${PHYSICS_ENGINE_ROOT}/Math/Mat4x4.h
    ${PHYSICS_ENGINE_ROOT}/Math/Mat4x4.inl)

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	# Add natvis file
  #set(SOURCE_FILES ${SOURCE_FILES} ${PHYSICS_ENGINE_ROOT}/PhysicsEngine.natvis)
endif()

source_group(TREE ${PHYSICS_ENGINE_ROOT} FILES ${SOURCE_FILES})

add_library(PhysicsEngine STATIC ${SOURCE_FILES})
target_include_directories(PhysicsEngine PUBLIC ${REPOSITORY_ROOT})
target_precompile_headers(PhysicsEngine PRIVATE ${PHYSICS_ENGINE_ROOT}/PhysicsEngine.h)

# TODO(Mikyan): Configs
