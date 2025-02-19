/*
 * File: ServiceManager.cpp
 * Author: trung.la
 * Date: 02-11-2025
 * Description: This file contains the implementation of the ServiceManager class.
 */

#include "core/services/ServiceManager.h"

ServiceManager &ServiceManager::instance()
{
	static ServiceManager serviceManager;
	return serviceManager;
}

ServiceManager::~ServiceManager()
{
	m_services.clear();
}
