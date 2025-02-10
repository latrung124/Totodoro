# TODO: add the services to another project
# the services should be separated and built to a package in the feature
# the interface headers would be installed to the include directory
if(WIN32)
    add_subdirectory(window-services)
endif (WIN32)

add_subdirectory(service-factory)
