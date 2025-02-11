/*
* File: ServiceManager.h
* Author: trung.la
* Date: 02-11-2025
* Description: This file contains the declaration of the ServiceManager class.
*/

#ifndef SERVICE_MANAGER_H
#define SERVICE_MANAGER_H

#include "core/services/ServiceConcreteHelper.h"

#include <QDebug>
#include <unordered_map>
#include <stdexcept>
#include <memory>

class ServiceManager
{
public:
    using IServicePtr = std::shared_ptr<IService>;
    static ServiceManager& instance();
    ~ServiceManager();

    ServiceManager(const ServiceManager&) = delete;
    ServiceManager& operator=(const ServiceManager&) = delete;

    ServiceManager(ServiceManager&&) = delete;
    ServiceManager& operator=(ServiceManager&&) = delete;

    template<service_concrete_helper::IServiceType Interface>
    [[nodiscard]] std::shared_ptr<Interface> registerService()
    {
        auto service = service_concrete_helper::createConcreteService<Interface>(getServiceFactory());
        auto serviceId = typeid(Interface).hash_code();
        try {
            if (m_services.find(serviceId) != m_services.end()) {
                throw std::runtime_error("Service already registered");
            } else {
                m_services[serviceId] = std::move(service);
            }
        } catch (const std::exception& e) {
            qDebug() << e.what();
        }
        return std::static_pointer_cast<Interface>(m_services[serviceId]);
    }

    template<service_concrete_helper::IServiceType Interface>
    void unregisterService()
    {
        auto serviceId = typeid(Interface).hash_code();
        try {
            if (m_services.find(serviceId) == m_services.end()) {
                throw std::runtime_error("Service not found");
            } else {
                m_services.erase(serviceId);
            }
        } catch (const std::exception& e) {
            qDebug() << e.what();
        }
    }

    template<service_concrete_helper::IServiceType Interface>
    [[nodiscard]] std::shared_ptr<Interface> getService()
    {
        auto serviceId = typeid(Interface).hash_code();
        try {
            if (m_services.find(serviceId) == m_services.end()) {
                throw std::runtime_error("Service not found");
            }
        } catch (const std::exception& e) {
            qDebug() << e.what();
        }
        return std::static_pointer_cast<Interface>(m_services[serviceId]);
    }

private:
    ServiceManager() = default;

    std::unordered_map<size_t, IServicePtr> m_services;
};

#endif // SERVICE_MANAGER_H
