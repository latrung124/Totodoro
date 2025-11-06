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
#include <utility>

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

	// Accept both rvalues and const lvalue references
	explicit ParamContainer(Args &&...args)
	    : m_params(std::forward<Args>(args)...)
	{
	}

	// Overload for const lvalue references (will copy)
	template<
	    typename... UArgs,
	    typename = std::enable_if_t<std::is_constructible_v<ParamTuple, const UArgs &...>>>
	explicit ParamContainer(const UArgs &...args)
	    : m_params(args...)
	{
	}

	/**
	 * @brief Access a parameter by index.
	 * @tparam Index The index of the parameter to access.
	 * @return The parameter at the specified index.
	 */
	template<std::size_t Index>
	decltype(auto) get() const noexcept
	{
		return std::get<Index>(m_params);
	}

	/**
	 * @brief Get all parameters as a tuple.
	 * @return The tuple of all parameters.
	 */
	const ParamTuple &getParams() const noexcept
	{
		return m_params;
	}

	/**
	 * @brief Convenience accessor for single-parameter containers.
	 * Only available when sizeof...(Args) == 1.
	 * @return The single parameter.
	 */
	template<std::size_t N = sizeof...(Args), typename = std::enable_if_t<N == 1>>
	decltype(auto) getParam() const noexcept
	{
		return std::get<0>(m_params);
	}

private:
	ParamTuple m_params;
};

} // namespace core::factories

#endif // PARAMCONTAINER_H
