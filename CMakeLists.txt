cmake_minimum_required(VERSION 3.16.0)

project (dll)

#include_directories(/usr/include/libusb-1.0)
#include_directories(/usr/local/include/json-c)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
    )

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/include/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.c"
    )

add_executable(dll.out main.c ${all_SRCS})
target_link_libraries(dll.out)# usb-1.0 json-c pthread rt)