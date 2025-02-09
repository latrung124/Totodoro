/*
* File: ServiceHandler.h
* Author: trung.la
* Date: 02-09-2025
* Description: This file contains the declaration of the ServiceHandler class.
*/

#ifndef SERVICE_HANDLER_H
#define SERVICE_HANDLER_H

class ServiceHandler
{
public:
    ServiceHandler() = default;
    virtual ~ServiceHandler() = default;

    ServiceHandler(const ServiceHandler&) = delete;
    ServiceHandler& operator=(const ServiceHandler&) = delete;
    ServiceHandler(ServiceHandler&&) = delete;
    ServiceHandler& operator=(ServiceHandler&&) = delete;
};

#endif // SERVICE_HANDLER_H