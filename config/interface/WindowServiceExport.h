/*
* File: WindowServiceExport.h
* Author: trung.la
* Date: 02-07-2025
* Description: This file contains the declaration of the WindowServiceExport class
*/

#ifndef WINDOW_SERVICE_EXPORT
#define WINDOW_SERVICE_EXPORT

#ifdef _WIN32
#    ifdef WMEDIA_SERVICE_LIBRARY_EXPORTS
#        define WMEDIA_SERVICE_API __declspec(dllexport) // When building the library
#    else
#        define WMEDIA_SERVICE_API __declspec(dllimport) // When consuming the library
#    endif
#else
#    define MEDIA_SERVICE_API // Non-Windows platforms
#endif

#endif // WINDOW_SERVICE_EXPORT