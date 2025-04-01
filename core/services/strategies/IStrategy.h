/*
 * File: trung.la
 * Date: 03-30-2025
 * Description: This file contains the interface for the Strategy pattern.
 */

#ifndef ISTRATEGY_H
#define ISTRATEGY_H

template<typename Type>
class IStrategy
{
public:
	virtual ~IStrategy() = default;

	virtual void execute(const Type &) = 0;
};

#endif // ISTRATEGY_H
