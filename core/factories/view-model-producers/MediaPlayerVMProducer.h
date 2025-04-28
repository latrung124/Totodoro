/*
 * File: MediaPlayerVMProducer.h
 * Author: trung.la
 * Date: 04-26-2025
 * Description: MediaPlayerVMProducer class definition
 * This class is responsible for creating MediaPlayerViewModel instances.
 */

#ifndef MEDIAPLAYERVMPRODUCER_H
#define MEDIAPLAYERVMPRODUCER_H

#include "core/factories/view-model-producers/ViewModelProducer.h"

class MediaPlayerVMProducer : public ViewModelProducer
{
public:
	MediaPlayerVMProducer() = default;
	~MediaPlayerVMProducer() = default;

	std::unique_ptr<ViewModel> createViewModel(ParamContainerBase *params = nullptr) override;
};

#endif // MEDIAPLAYERVMPRODUCER_H
