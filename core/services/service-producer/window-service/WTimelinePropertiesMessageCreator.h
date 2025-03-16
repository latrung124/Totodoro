/*
 * File: WTimelinePropertiesMessageCreator.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WTimelinePropertiesMessageCreator class.
 */

#ifndef WTIMELINEPROPERTIESMESSAGECREATOR_H
#define WTIMELINEPROPERTIESMESSAGECREATOR_H

#include "core/services/service-producer/ServiceMessageCreator.h"

class WTimelinePropertiesMessageCreator : public ServiceMessageCreator
{
public:
	virtual ServiceMessageUPtr create() const override;
};

#endif // WTIMELINEPROPERTIESMESSAGECREATOR_H
