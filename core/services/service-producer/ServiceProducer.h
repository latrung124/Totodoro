/*
 * File: ServiceProducer.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: This file contains the declaration of the ServiceProducer class.
 */

#ifndef SERVICE_CONSUMER_H
#define SERVICE_CONSUMER_H

class ServiceProducer
{
public:
	ServiceProducer() = default;
	virtual ~ServiceProducer() = default;

	ServiceProducer(const ServiceProducer &) = delete;
	ServiceProducer &operator=(const ServiceProducer &) = delete;
	ServiceProducer(ServiceProducer &&) = delete;
	ServiceProducer &operator=(ServiceProducer &&) = delete;
};

#endif // SERVICE_CONSUMER_H
