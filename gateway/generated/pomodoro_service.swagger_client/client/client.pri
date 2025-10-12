QT += network

HEADERS += \
# Models
    $${PWD}/OAIPomodoroServiceCreateSessionBody.h \
    $${PWD}/OAIPomodoroServiceUpdateSessionBody.h \
    $${PWD}/OAIPomodoro_serviceCreateSessionResponse.h \
    $${PWD}/OAIPomodoro_serviceDeleteSessionResponse.h \
    $${PWD}/OAIPomodoro_serviceGetSessionByIdResponse.h \
    $${PWD}/OAIPomodoro_serviceGetSessionsResponse.h \
    $${PWD}/OAIPomodoro_servicePomodoroSession.h \
    $${PWD}/OAIPomodoro_serviceSessionStatus.h \
    $${PWD}/OAIPomodoro_serviceSessionType.h \
    $${PWD}/OAIPomodoro_serviceUpdateSessionResponse.h \
    $${PWD}/OAIProtobufAny.h \
    $${PWD}/OAIRpcStatus.h \
# APIs
    $${PWD}/OAIPomodoroServiceApi.h \
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
    $${PWD}/OAIPomodoroServiceCreateSessionBody.cpp \
    $${PWD}/OAIPomodoroServiceUpdateSessionBody.cpp \
    $${PWD}/OAIPomodoro_serviceCreateSessionResponse.cpp \
    $${PWD}/OAIPomodoro_serviceDeleteSessionResponse.cpp \
    $${PWD}/OAIPomodoro_serviceGetSessionByIdResponse.cpp \
    $${PWD}/OAIPomodoro_serviceGetSessionsResponse.cpp \
    $${PWD}/OAIPomodoro_servicePomodoroSession.cpp \
    $${PWD}/OAIPomodoro_serviceSessionStatus.cpp \
    $${PWD}/OAIPomodoro_serviceSessionType.cpp \
    $${PWD}/OAIPomodoro_serviceUpdateSessionResponse.cpp \
    $${PWD}/OAIProtobufAny.cpp \
    $${PWD}/OAIRpcStatus.cpp \
# APIs
    $${PWD}/OAIPomodoroServiceApi.cpp \
# Others
    $${PWD}/OAIHelpers.cpp \
    $${PWD}/OAIHttpRequest.cpp \
    $${PWD}/OAIHttpFileElement.cpp \
    $${PWD}/OAIOauth.cpp
