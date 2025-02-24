/*
 * File: ScopedThread.h
 * Author: trung.la
 * Date: 02-24-2025
 * Description: This file contains the declaration of the ScopedThread class.
 */

#ifndef SCOPED_THREAD_H
#define SCOPED_THREAD_H

#include <stdexcept>
#include <thread>

namespace utils {

class ScopedThread
{
	std::thread m_thread;

public:
	explicit ScopedThread(std::thread thread)
	    : m_thread(std::move(thread))
	{
		if (!m_thread.joinable()) {
			throw std::logic_error("No thread");
		}
	}

	~ScopedThread()
	{
		m_thread.join();
	}

	ScopedThread(const ScopedThread &) = delete;
	ScopedThread &operator=(const ScopedThread &) = delete;
};

} // namespace utils

#endif // SCOPED_THREAD_H
