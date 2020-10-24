cmake_minimum_required(VERSION 3.19)
add_definitions(-std=c++11)
# Define project name
project(boost_serialization)

find_package(Boost COMPONENTS serialization REQUIRED)

if(NOT Boost_FOUND)
    message("NOT found Boost")
endif()

include_directories(${Boost_INCLUDE_DIRS})

add_executable(main main.cpp)

link_directories("/usr/lib/x86_64-linux-gnu/")

target_link_libraries(main ${Boost_LIBRARIES})
