/**
 * @file TaskGroupsVMProducer.h
 * @author trung.la
 * @date 11-10-2025
 * @brief Declaration of the TaskGroupsVMProducer class for producing TaskGroupsViewModel instances.
 */

#ifndef TASKGROUPSVMPRODUCER_H
#define TASKGROUPSVMPRODUCER_H

#include "core/factories/view-model-producers/ViewModelProducer.h"

class TaskGroupsVMProducer : public ViewModelProducer
{
public:
	TaskGroupsVMProducer() = default;
	~TaskGroupsVMProducer() = default;

	std::unique_ptr<QObject> createViewModel(ParamContainerBase *params = nullptr) override;
};

#endif // TASKGROUPSVMPRODUCER_H
