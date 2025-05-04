/*
 * File: ServiceFactoryExport.h
 * Author: trung.la
 * Date: 02-07-2025
 * Description: This file contains the declaration of the ServiceFactoryExport class
 */

#ifndef SERVICE_FACTORY_EXPORT
#define SERVICE_FACTORY_EXPORT

#ifdef _WIN32
#	ifdef SERVICE_FACTORY_LIBRARY_EXPORTS
#		define SERVICE_FACTORY_API __declspec(dllexport) // When building the library
#	else
#		define SERVICE_FACTORY_API __declspec(dllimport) // When consuming the library
#	endif
#else
#	define SERVICE_FACTORY_API // Non-Windows platforms
#endif

#endif // SERVICE_FACTORY_EXPORT
