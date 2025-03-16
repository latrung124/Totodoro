/*
 * File: ServiceMessageProducer.h
 * Author: trung.la
 * Date: 02-15-2025
 * Description: This file contains the declaration of the ServiceMessageProducer class.
 */

#ifndef SERVICE_MESSAGE_PRODUCER_H
#define SERVICE_MESSAGE_PRODUCER_H

#include <functional>
#include <memory>
#include <typeindex>
#include <unordered_map>

#include "core/services/service-producer/ServiceMessageCreator.h"

/**
 * @class ServiceMessageProducer
 * @brief A modern factory pattern-based class for creating `ServiceMessage` instances.
 *
 * This class follows the factory pattern to dynamically register and create
 * `ServiceMessage` instances using registered creator types. It ensures that
 * each registered creator is associated with a specific type using `std::type_index`.
 *
 * @note This class is implemented as a singleton.
 */
class ServiceMessageProducer
{
public:
	using ServiceMessageUPtr = std::unique_ptr<ServiceMessage>;

	/**
	 * @brief Gets the singleton instance of the `ServiceMessageProducer` class.
	 *
	 * This function returns the singleton instance of the `ServiceMessageProducer` class.
	 *
	 * @return ServiceMessageProducer& The singleton instance of the `ServiceMessageProducer` class.
	 */
	static ServiceMessageProducer &getInstance();
	virtual ~ServiceMessageProducer() = default;

	/**
	 * @brief Registers a creator type for producing ServiceMessage instances.
	 *
	 * This function stores a lambda function that creates an instance of
	 * `CreatorType` and associates it with the type information of `CreatorType`.
	 *
	 * @tparam CreatorType The type of the creator class, which must have a default constructor.
	 */
	template<typename CreatorType>
	void registerCreator()
	{
		std::type_index type = std::type_index(typeid(CreatorType));
		m_creators[type] = []() {
			return std::make_unique<CreatorType>();
		};
	}

	/**
	 * @brief Produces a `ServiceMessage` instance using the registered creator type.
	 *
	 * This function searches for a registered creator associated with `CreatorType`.
	 * If found, it calls the stored creator function to generate a new instance.
	 *
	 * @tparam CreatorType The type of the creator class used to produce the `ServiceMessage`.
	 * @return std::unique_ptr<ServiceMessage> A unique pointer to the created `ServiceMessage`
	 *         instance, or `nullptr` if no matching creator is found.
	 */
	template<typename CreatorType>
	[[nodiscard]] std::unique_ptr<ServiceMessage> produce() const
	{
		std::type_index type = std::type_index(typeid(CreatorType));
		const auto &it = m_creators.find(type);
		if (it != m_creators.end()) {
			return it->second()->create();
		}

		return nullptr;
	}

private:
	/// Alias for a function that creates a `ServiceMessageCreator` instance.
	using CreationFunc = std::function<std::unique_ptr<ServiceMessageCreator>()>;

	ServiceMessageProducer() = default;

	/// Stores the mapping between type indices and their corresponding creation functions.
	std::unordered_map<std::type_index, CreationFunc> m_creators;
};

#endif // SERVICE_MESSAGE_PRODUCER_H
