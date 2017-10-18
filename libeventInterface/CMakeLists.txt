
cmake_minimum_required(VERSION 2.6)

project(libevent_interface)

message(STATUS "binary dir: " ${PROJECT_BINARY_DIR})
message(STATUS "source dir: " ${PROJECT_SOURCE_DIR})

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -g -ggdb -Wall")
set(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -O3 -Wall")

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src DIR_SRCS)

set(SRC_LIST ${DIR_SRCS})
add_library(eventInterface SHARED ${SRC_LIST})

#ADD_EXECUTABLE(libevent_test libevent_test.cpp  ${SRC_LIST})
#TARGET_LINK_LIBRARIES(libevent_test event)



