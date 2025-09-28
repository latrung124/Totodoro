/**
 * @file ApiCommandFactory.h
 * @author trung.la
 * @date 09-28-2025
 * @brief Factory class for creating API command instances.
 */

#pragma once

#include <memory>
#include <utility>
#include <type_traits>
#include <concepts>

#include "IApiCommand.h"

class ApiCommandFactory
{
public:
    static ApiCommandFactory& instance()
    {
        static ApiCommandFactory factory;
        return factory;
    }


    /**
     * createCommand
     * Safely creates a Q_OBJECT based command (derived from IApiCommand) and returns it
     * as a shared_ptr<IApiCommand>. We avoid std::make_shared because mixing Qt's
     * parent/child ownership with make_shared's control block can be problematic.
     * We use a custom deleter calling deleteLater() so destruction happens on the
     * Qt event loop (thread‑safe if queued).
     */
    template<typename CommandType, typename... Args>
        requires std::derived_from<CommandType, IApiCommand> &&
                 std::constructible_from<CommandType, Args...>
    std::shared_ptr<IApiCommand> createCommand(Args&&... args)
    {
        static_assert(std::is_base_of_v<QObject, CommandType>,
                      "CommandType must inherit QObject (and IApiCommand).");

        // Allocate raw (QObject derived)
        auto* raw = new CommandType(std::forward<Args>(args)...);

        // Custom deleter: schedule deletion via Qt event loop
        auto deleter = [](IApiCommand* p) {
            if (!p) return;
            // Use deleteLater to ensure safe destruction in Qt context
            p->deleteLater();
        };

        return std::shared_ptr<IApiCommand>(raw, deleter);
    }

    // (Optional) typed overload if caller wants the concrete type
    template<typename CommandType, typename... Args>
        requires std::derived_from<CommandType, IApiCommand> &&
                 std::constructible_from<CommandType, Args...>
    std::shared_ptr<CommandType> createTyped(Args&&... args)
    {
        static_assert(std::is_base_of_v<QObject, CommandType>,
                      "CommandType must inherit QObject (and IApiCommand).");

        auto* raw = new CommandType(std::forward<Args>(args)...);
        auto deleter = [](CommandType* p) {
            if (!p) return;
            p->deleteLater();
        };
        return std::shared_ptr<CommandType>(raw, deleter);
    }
};