cmake_minimum_required(VERSION 2.8.4)
project(OS_F14_Prj1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Hash.cpp Bucket.cpp Record.cpp InvertedIndexList.cpp TownNode.cpp RecordPointer.cpp Triple.cpp)
add_executable(OS_F14_Prj1 ${SOURCE_FILES})