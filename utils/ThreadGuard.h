/*
* File: ThreadGuard.h
* Author: trung.la
* Date: 02-10-2025
* Description: Implementation for Thread Guard
*/

#ifndef THREAD_GUARD_H
#define THREAD_GUARD_H

#include <thread>

namespace utils {

class ThreadGuard
{
    std::thread& m_thread;
public:
    ThreadGuard(std::thread &thread) : m_thread(thread) {}
    ~ThreadGuard() {
        if (m_thread.joinable()) {
            m_thread.join();
        }
    }

    ThreadGuard(const ThreadGuard&) = delete;
    ThreadGuard& operator=(const ThreadGuard&) = delete;
};

} // namespace utils

#endif // THREAD_GUARD_H