/**
 * @file ApiGatewayManagerFactory.cpp
 * @author trung.la
 * @date 09-25-2025
 * @brief This file contains the implementation of the ApiGatewayManagerFactory class.
 */

#include "ApiGatewayManagerFactory.h"

#include "CommonDefine.h"
#include "PomodoroApiGatewayManager.h"
#include "TaskManagementApiGatewayManager.h"
#include "UserApiGatewayManager.h"

std::shared_ptr<IApiGatewayManager> ApiGatewayManagerFactory::createManager(gateway::RouteType managerType) {
    switch (managerType) {
        case gateway::RouteType::Pomodoro:
            return std::make_shared<PomodoroApiGatewayManager>();
        case gateway::RouteType::TaskManagement:
            return std::make_shared<TaskManagementApiGatewayManager>();
        case gateway::RouteType::User:
            return std::make_shared<UserApiGatewayManager>();
        default:
            return nullptr;
    }
}
