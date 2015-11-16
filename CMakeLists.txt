cmake_minimum_required(VERSION 3.3)
project(QSDE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Tick.cpp Tick.h HistData.cpp HistData.h HistData.cpp HistData.h Tick.cpp Tick.h)
add_executable(QSDE ${SOURCE_FILES})