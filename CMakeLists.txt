cmake_minimum_required(VERSION 3.0)

project(cppcodetest)

set(CMAKE_CXX_FLAGS "-g -static-libstdc++")

set(SOURCE pydictionarychlng.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})