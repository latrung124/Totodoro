/*
 * File: ServiceExport.h
 * Author: trung.la
 * Date: 02-16-2025
 * Description: This file contains the declaration of the ServiceExport class.
 */

#ifndef SERVICE_EXPORT_H
#define SERVICE_EXPORT_H

#ifdef _WIN32
#	ifdef SERVICE_LIBRARY_EXPORTS
#		define SERVICE_API __declspec(dllexport) // When building the library
#	else
#		define SERVICE_API __declspec(dllimport) // When consuming the library
#	endif
#else
#	define SERVICE_API // Non-Windows platforms
#endif

#endif // SERVICE_EXPORT_H
