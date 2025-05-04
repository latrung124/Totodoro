/*
 * File: IServiceListener.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Interface for Service Listener
 */

#ifndef INTERFACES_ISERVICELISTENER_H_
#define INTERFACES_ISERVICELISTENER_H_

class IServiceListener
{
public:
	IServiceListener() = default;
	virtual ~IServiceListener() = default;

	IServiceListener(const IServiceListener &) = delete;
	IServiceListener &operator=(const IServiceListener &) = delete;
	IServiceListener(IServiceListener &&) = delete;
	IServiceListener &operator=(IServiceListener &&) = delete;
};

#endif // INTERFACES_ISERVICELISTENER_H_
