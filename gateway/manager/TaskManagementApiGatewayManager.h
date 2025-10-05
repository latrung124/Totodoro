/**
 * @file TaskManagementApiGatewayManager.h
 * @author trung.la
 * @date 09-23-2025
 * @brief This file contains the declaration of the TaskManagementApiGatewayManager class.
 */

#pragma once

#include <map>

#include "IApiGatewayManager.h"

namespace gateway
{
    struct TaskProperties;
    struct TaskGroupProperties;
    struct ApiResponse;
}

class TaskManagementApiGatewayManager : public IApiGatewayManager
{
public:
    using ApiResponsePtr = std::shared_ptr<gateway::ApiResponse>;
    using ResponseCallback = std::function<void(const ApiResponsePtr&)>;
    using ErrorCallback = std::function<void(const std::string&)>;
    using TaskContainer = std::vector<gateway::TaskProperties>;
    using TaskGroupContainer = std::vector<gateway::TaskGroupProperties>;

    explicit TaskManagementApiGatewayManager(QObject* parent = nullptr) : IApiGatewayManager(parent) {}
    ~TaskManagementApiGatewayManager() override = default;

    bool registerResponseCallback(gateway::RequestType requestType, const ResponseCallback& callback) override;
    bool unregisterResponseCallback(gateway::RequestType requestType) override;

    bool createTask(const gateway::TaskProperties& taskProperties);
    bool getTasks(const std::string& groupId, const std::string& userId = "");
    bool updateTask(const gateway::TaskProperties& taskProperties);
    bool deleteTask(const std::string& taskId);
    bool createTaskGroup(const gateway::TaskGroupProperties& groupProperties);
    bool getTaskGroups(const std::string& userId);
    bool updateTaskGroup(const gateway::TaskGroupProperties& groupProperties);
    bool deleteTaskGroup(const std::string& groupId);

private:
    std::map<gateway::RequestType, ResponseCallback> m_responseCallbacks;
};
