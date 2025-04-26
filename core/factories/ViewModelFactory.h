/*
 * File: ViewModelFactory.h
 * Author: trung.la
 * Date: 04-26-2025
 * Description: ViewModelFactory class definition
 * This class is responsible for creating ViewModel instances.
 */

#ifndef VIEWMODELFACTORY_H
#define VIEWMODELFACTORY_H

#include <functional>
#include <memory>
#include <typeindex>

class ViewModelProducer;

/**
 * @brief ViewModelFactory is a factory class that creates instances of ViewModelProducer.
 * It uses a map to store the creation functions for different ViewModelProducer types.
 */
class ViewModelFactory
{
private:
	using CreationFunc = std::function<std::unique_ptr<ViewModelProducer>()>;
	std::unordered_map<std::type_index, CreationFunc> m_viewModelCreators;

public:
	/**
	 * @brief Registers a ViewModelProducer type with the factory.
	 * @tparam VMProducerType The type of the ViewModelProducer to register.
	 * @note This function uses a lambda to create instances of the specified type.
	 */
	template<typename VMProducerType>
	void registerViewModel()
	{
		std::type_index typeIndex = std::type_index(typeid(VMProducerType));
		m_viewModelCreators[typeIndex] = []() {
			return std::make_unique<VMProducerType>();
		};
	}

	/**
	 * @brief Creates an instance of the specified ViewModelProducer type.
	 * @tparam VMProducerType The type of the ViewModelProducer to create.
	 * @return A unique pointer to the created ViewModelProducer instance.
	 * @note This function uses a lambda to create instances of the specified type.
	 * If the type is not registered, it returns a nullptr.
	 */
	template<typename VMProducerType>
	[[nodiscard]] std::unique_ptr<ViewModelProducer> createViewModel()
	{
		std::type_index = std::type_index(typeid(VMProducerType));
		auto it = m_viewModelCreators.find(typeIndex);
		if (it != m_viewModelCreators.end()) {
			return it->second();
		}

		return nullptr; // TODO: Handle error case (e.g., throw an exception or return a default instance)
	}

	/**
	 * @brief Creates an instance of the specified ViewModelProducer type with parameters.
	 * @tparam ConcreteProducer The type of the ViewModelProducer to create.
	 * @tparam Args The types of the parameters to pass to the constructor.
	 * @param args The parameters to pass to the constructor.
	 * @return A unique pointer to the created ViewModelProducer instance.
	 * @note This function uses a lambda to create instances of the specified type.
	 * If the type is not registered, it returns a nullptr.
	 */
	template<typename ConcreteProducer, typename... Args>
	[[nodiscard]] std::unique_ptr<ViewModelProducer> createViewModel(Args &&...args)
	{
		std::type_index typeIndex = std::type_index(typeid(ConcreteProducer));
		auto it = m_viewModelCreators.find(typeIndex);
		if (it != m_viewModelCreators.end()) {
			auto params = std::make_unique<ParamContainer<Args...>>(std::forward<Args>(args)...);
			return it->second()->createViewModel(
			    params.get()); // the unique_ptr will be passed to the producer, and after that, it
			                   // will be deleted
		}

		return nullptr; // TODO: Handle error case (e.g., throw an exception or return a default instance)
	}
};

#endif // VIEWMODELFACTORY_H
