QT += network

HEADERS += \
# Models
    $${PWD}/OAIProtobufAny.h \
    $${PWD}/OAIRpcStatus.h \
    $${PWD}/OAIUserServiceUpdateSettingsBody.h \
    $${PWD}/OAIUserServiceUpdateUserBody.h \
    $${PWD}/OAIUser_serviceCreateUserRequest.h \
    $${PWD}/OAIUser_serviceCreateUserResponse.h \
    $${PWD}/OAIUser_serviceGetSettingsResponse.h \
    $${PWD}/OAIUser_serviceGetUserResponse.h \
    $${PWD}/OAIUser_serviceSettings.h \
    $${PWD}/OAIUser_serviceUpdateSettingsResponse.h \
    $${PWD}/OAIUser_serviceUpdateUserResponse.h \
    $${PWD}/OAIUser_serviceUser.h \
# APIs
    $${PWD}/OAIUserServiceApi.h \
# Others
    $${PWD}/OAIHelpers.h \
    $${PWD}/OAIHttpRequest.h \
    $${PWD}/OAIObject.h \
    $${PWD}/OAIEnum.h \
    $${PWD}/OAIHttpFileElement.h \
    $${PWD}/OAIServerConfiguration.h \
    $${PWD}/OAIServerVariable.h \
    $${PWD}/OAIOauth.h

SOURCES += \
# Models
    $${PWD}/OAIProtobufAny.cpp \
    $${PWD}/OAIRpcStatus.cpp \
    $${PWD}/OAIUserServiceUpdateSettingsBody.cpp \
    $${PWD}/OAIUserServiceUpdateUserBody.cpp \
    $${PWD}/OAIUser_serviceCreateUserRequest.cpp \
    $${PWD}/OAIUser_serviceCreateUserResponse.cpp \
    $${PWD}/OAIUser_serviceGetSettingsResponse.cpp \
    $${PWD}/OAIUser_serviceGetUserResponse.cpp \
    $${PWD}/OAIUser_serviceSettings.cpp \
    $${PWD}/OAIUser_serviceUpdateSettingsResponse.cpp \
    $${PWD}/OAIUser_serviceUpdateUserResponse.cpp \
    $${PWD}/OAIUser_serviceUser.cpp \
# APIs
    $${PWD}/OAIUserServiceApi.cpp \
# Others
    $${PWD}/OAIHelpers.cpp \
    $${PWD}/OAIHttpRequest.cpp \
    $${PWD}/OAIHttpFileElement.cpp \
    $${PWD}/OAIOauth.cpp
