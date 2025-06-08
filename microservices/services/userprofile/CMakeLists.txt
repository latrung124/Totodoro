set(HANDLER_SOURCES handlers/UserProfileHandler.cpp
                    handlers/UserProfileHandler.h)

set(MODEL_SOURCES models/User.cpp models/User.h)

set(UTILS_SOURCES utils/Utils.h)

set(REPOSITORY_SOURCES
    repositories/IUserRepository.h repositories/SQLiteUserRepository.h
    repositories/SQLiteUserRepository.cpp)

set(SOURCES ${HANDLER_SOURCES} ${MODEL_SOURCES} ${REPOSITORY_SOURCES}
            UserProfileService.h UserProfileService.cpp main.cpp)
add_executable(userprofile ${SOURCES})

target_include_directories(
  userprofile
  PUBLIC ${CMAKE_SOURCE_DIR}/microservices
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/handlers
          ${CMAKE_CURRENT_SOURCE_DIR}/models
          ${CMAKE_CURRENT_SOURCE_DIR}/repositories
          ${CMAKE_CURRENT_SOURCE_DIR}/utils)

target_link_libraries(userprofile PRIVATE microservices)
