/*
 * File: ServiceConsumer.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: This file contains the declaration of the ServiceConsumer class.
 */

#ifndef SERVICE_CONSUMER_H
#define SERVICE_CONSUMER_H

class ServiceConsumer
{
public:
	ServiceConsumer() = default;
	virtual ~ServiceConsumer() = default;

	ServiceConsumer(const ServiceConsumer &) = delete;
	ServiceConsumer &operator=(const ServiceConsumer &) = delete;
	ServiceConsumer(ServiceConsumer &&) = delete;
	ServiceConsumer &operator=(ServiceConsumer &&) = delete;
};

#endif // SERVICE_CONSUMER_H
