set(HANDLER_SOURCES handler/UserProfileHandler.cpp handler/UserProfileHandler.h)

set(MODEL_SOURCES models/User.cpp models/User.h)

set(REPOSITORY_SOURCES repositories/IUserRepository.cpp
                       repositories/SQLiteUserRepository.h)

set(SOURCES ${HANDLER_SOURCES} ${MODEL_SOURCES} ${REPOSITORY_SOURCES}
            UserProfileService.h UserProfileService.cpp main.cpp)
add_executable(userprofile ${SOURCES})
