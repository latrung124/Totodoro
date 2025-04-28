/*
 * File: ParamContainer.h
 * Author: trung.la
 * Date: 04-26-2025
 * Description: ParamContainer class definition
 * This class serves as a base class for all parameter containers used for constructing view model.
 */

#ifndef PARAMCONTAINER_H
#define PARAMCONTAINER_H

#include <tuple>

namespace core::factories {

// Base class for parameter containers
class ParamContainerBase
{
public:
	virtual ~ParamContainerBase() = default;
};

/**
 *  @brief ParamContainer is a template class that holds a tuple of parameters.
 *  It inherits from ParamContainerBase and provides a way to access the parameters
 *  using a tuple.
 *  @tparam Args The types of the parameters to be held in the container.
 *  @note This class is used to create a container for parameters that can be passed
 *  to a view model or any other object that requires multiple parameters.
 */
template<typename... Args>
class ParamContainer : public ParamContainerBase
{
public:
	using ParamTuple = std::tuple<Args...>;

	explicit ParamContainer(Args... args)
	    : m_params(std::make_tuple(args...))
	{
	}

	/**
	 * @brief Access a parameter by index.
	 * @tparam Index The index of the parameter to access.
	 * @return The parameter at the specified index.
	 * @note This function uses decltype to deduce the return type based on the index.
	 */
	template<std::size_t Index>
	auto get() const -> decltype(std::get<Index>(this->m_params))
	{
		return std::get<Index>(this->m_params);
	}

	ParamTuple getParams() const
	{
		return m_params;
	}

private:
	ParamTuple m_params;
};

} // namespace core::factories

#endif // PARAMCONTAINER_H
