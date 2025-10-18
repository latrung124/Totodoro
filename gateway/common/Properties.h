/**
* @file common/Properties.h
 * @author trung.la
 * @date 09-18-2025
 * @brief Common properties used across the gateway module.
 */

#pragma once

#include <variant>

#include "common/UserProperties.h"
#include "common/TaskProperties.h"
#include "common/PomodoroProperties.h"

namespace gateway {

struct Properties
{
    using PropertyVariant = std::variant<
        UserProperties,
        UserSettings,
        TaskProperties,
        PomodoroSessionProperties
    >;

    template<typename T>
    T getProperty() const
    {
        // check type before get it
        if (std::holds_alternative<T>(property)) {
            return std::get<T>(property);
        }
        throw std::bad_variant_access();
    }

    PropertyVariant property;
};

} // namespace gateway
