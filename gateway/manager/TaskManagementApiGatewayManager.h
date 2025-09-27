/**
 * @file TaskManagementApiGatewayManager.h
 * @author trung.la
 * @date 09-23-2025
 * @brief This file contains the declaration of the TaskManagementApiGatewayManager class.
 */

#pragma once

#include <string>
#include <memory>
#include <functional>

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

    bool onCreateTask(const gateway::TaskProperties& taskProps,
                      const ResponseCallback& onSuccess,
                      const ErrorCallback& onError);

    bool onGetTasks(const std::string& groupId,
                   TaskContainer& outTasks,
                   const ResponseCallback& onSuccess,
                   const ErrorCallback& onError);
    
    bool onUpdateTask(const gateway::TaskProperties& taskProps,
                      const ResponseCallback& onSuccess,
                      const ErrorCallback& onError);

    bool onDeleteTask(const std::string& taskId,
                      const ResponseCallback& onSuccess,
                      const ErrorCallback& onError);

    bool onCreateTaskGroup(const gateway::TaskGroupProperties& groupProps,
                           const ResponseCallback& onSuccess,
                           const ErrorCallback& onError);

    bool onGetTasksGroups(const std::string& userId,
                        TaskGroupContainer& outGroups,
                        const ResponseCallback& onSuccess,
                        const ErrorCallback& onError);
    
    bool onUpdateTaskGroup(const gateway::TaskGroupProperties& groupProps,
                           const ResponseCallback& onSuccess,
                           const ErrorCallback& onError);

    bool onDeleteTaskGroup(const std::string& groupId,
                           const ResponseCallback& onSuccess,
                           const ErrorCallback& onError);
};