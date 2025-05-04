/*
 * File: IService.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Interface for Service
 */

#ifndef INTERFACES_ISERVICE_H_
#define INTERFACES_ISERVICE_H_

#include <ServiceExport.h>

class IServiceListener;

class SERVICE_API IService
{
public:
	IService() = default;
	virtual ~IService() = default;

	virtual void registerListener(const IServiceListener *listener) = 0;
	virtual void unregisterListener(const IServiceListener *listener) = 0;

	IService(const IService &) = delete;
	IService &operator=(const IService &) = delete;
	IService(IService &&) = delete;
	IService &operator=(IService &&) = delete;
};

#endif // INTERFACES_ISERVICE_H_
