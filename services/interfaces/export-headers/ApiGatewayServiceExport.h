/**
 * @file ApiGatewayServiceExport.h
 * @author trung.la
 * @date 09-20-2025
 * @brief ApiGatewayServiceExport class
 */

#ifndef API_GATEWAY_SERVICE_EXPORT
#define API_GATEWAY_SERVICE_EXPORT

#ifdef _WIN32
#	ifdef APIGATEWAY_SERVICE_LIBRARY_EXPORTS
#		define APIGATEWAY_SERVICE_API __declspec(dllexport) // When building the library
#	else
#		define APIGATEWAY_SERVICE_API __declspec(dllimport) // When consuming the library
#	endif
#else
#	define APIGATEWAY_SERVICE_API // Non-Windows platforms
#endif

#endif // API_GATEWAY_SERVICE_EXPORT
