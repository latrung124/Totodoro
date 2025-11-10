/**
 * @file TaskGroupsVMProducer.cpp
 * @author trung.la
 * @date 11-10-2025
 * @brief Implementation of the TaskGroupsVMProducer class for producing TaskGroupsViewModel instances.
 */

#include "TaskGroupsVMProducer.h"
#include "helpers/ParamContainerHelper.h"
#include "view-models/taskmanagement/TaskGroupsViewModel.h"

std::unique_ptr<QObject> TaskGroupsVMProducer::createViewModel(ParamContainerBase *params)
{
	return std::make_unique<TaskGroupsViewModel>();
}
