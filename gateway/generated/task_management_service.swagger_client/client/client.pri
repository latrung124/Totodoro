QT += network

HEADERS += \
# Models
    $${PWD}/OAIProtobufAny.h \
    $${PWD}/OAIRpcStatus.h \
    $${PWD}/OAITaskManagementServiceCreateTaskBody.h \
    $${PWD}/OAITaskManagementServiceUpdateTaskBody.h \
    $${PWD}/OAITaskManagementServiceUpdateTaskGroupBody.h \
    $${PWD}/OAITask_managementCreateTaskGroupRequest.h \
    $${PWD}/OAITask_managementCreateTaskGroupResponse.h \
    $${PWD}/OAITask_managementCreateTaskResponse.h \
    $${PWD}/OAITask_managementDeleteTaskGroupResponse.h \
    $${PWD}/OAITask_managementDeleteTaskResponse.h \
    $${PWD}/OAITask_managementGetTaskGroupsResponse.h \
    $${PWD}/OAITask_managementGetTasksResponse.h \
    $${PWD}/OAITask_managementTask.h \
    $${PWD}/OAITask_managementTaskGroup.h \
    $${PWD}/OAITask_managementTaskGroupPriority.h \
    $${PWD}/OAITask_managementTaskGroupStatus.h \
    $${PWD}/OAITask_managementTaskPriority.h \
    $${PWD}/OAITask_managementTaskStatus.h \
    $${PWD}/OAITask_managementUpdateTaskGroupResponse.h \
    $${PWD}/OAITask_managementUpdateTaskResponse.h \
# APIs
    $${PWD}/OAITaskManagementServiceApi.h \
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
    $${PWD}/OAITaskManagementServiceCreateTaskBody.cpp \
    $${PWD}/OAITaskManagementServiceUpdateTaskBody.cpp \
    $${PWD}/OAITaskManagementServiceUpdateTaskGroupBody.cpp \
    $${PWD}/OAITask_managementCreateTaskGroupRequest.cpp \
    $${PWD}/OAITask_managementCreateTaskGroupResponse.cpp \
    $${PWD}/OAITask_managementCreateTaskResponse.cpp \
    $${PWD}/OAITask_managementDeleteTaskGroupResponse.cpp \
    $${PWD}/OAITask_managementDeleteTaskResponse.cpp \
    $${PWD}/OAITask_managementGetTaskGroupsResponse.cpp \
    $${PWD}/OAITask_managementGetTasksResponse.cpp \
    $${PWD}/OAITask_managementTask.cpp \
    $${PWD}/OAITask_managementTaskGroup.cpp \
    $${PWD}/OAITask_managementTaskGroupPriority.cpp \
    $${PWD}/OAITask_managementTaskGroupStatus.cpp \
    $${PWD}/OAITask_managementTaskPriority.cpp \
    $${PWD}/OAITask_managementTaskStatus.cpp \
    $${PWD}/OAITask_managementUpdateTaskGroupResponse.cpp \
    $${PWD}/OAITask_managementUpdateTaskResponse.cpp \
# APIs
    $${PWD}/OAITaskManagementServiceApi.cpp \
# Others
    $${PWD}/OAIHelpers.cpp \
    $${PWD}/OAIHttpRequest.cpp \
    $${PWD}/OAIHttpFileElement.cpp \
    $${PWD}/OAIOauth.cpp
