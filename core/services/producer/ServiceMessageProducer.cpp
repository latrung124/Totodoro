/*
 * File: ServiceMessageProducer.cpp
 * Author: trung.la
 * Date: 02-15-2025
 * Description: This file contains the implementation of the ServiceMessageProducer class.
 */

#include "ServiceMessageProducer.h"

ServiceMessageProducer &ServiceMessageProducer::getInstance()
{
	static ServiceMessageProducer instance;
	return instance;
}
