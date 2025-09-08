/**
 * @file Gateway.h
 * @author trung.la
 * @date 09-07-2025
 * @brief Declaration of the Gateway to communicate with Backend services via RestApi.
 */

#pragma once

#include <memory>

namespace gateway {

class PomodoroOpenApiController;

class Gateway
{
public:
    Gateway() = default;
    ~Gateway() = default;

    bool start();
    bool stop();

private:
    bool initialize();

    std::shared_ptr<PomodoroOpenApiController> mPomodoroController;    
};

} // namespace gateway
