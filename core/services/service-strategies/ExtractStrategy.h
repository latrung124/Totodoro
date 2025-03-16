/*
 * File: ExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the ExtractStrategy class.
 */

#ifndef EXTRACT_STRATEGY_H
#define EXTRACT_STRATEGY_H

template<typename Type>
class ExtractStrategy
{
public:
	virtual ~ExtractStrategy() = default;

	virtual void extract(const Type &) = 0;
};

#endif // EXTRACT_STRATEGY_H
