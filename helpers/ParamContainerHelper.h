/*
* File: ParamContainerHelper.h
* Author: trung.la
* Date: 04-26-2025
* Description: ParamContainerHelper class definition
* This class provides helper functions for working with ParamContainer instances.
*/

#ifndef PARAMCONTAINERHELPER_H
#define PARAMCONTAINERHELPER_H

#include <tuple>
#include <memory>

#include "core/factories/ParamContainer.h"

namespace helpers {

template<typename T, typename... Args>
std::unique_ptr<T> createWithParams(const core::factories::ParamContainer<Args...>* container) {
    return std::apply(
        [](auto&&... args) { return std::make_unique<T>(std::forward<decltype(args)>(args)...); },
        container->params
    );
}

}
#endif // PARAMCONTAINERHELPER_H