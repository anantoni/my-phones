cmake_minimum_required(VERSION 2.8.4)
project(OS_F14_Prj1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp hash/Hash.cpp hash/Bucket.cpp record/Record.cpp inverted_index/InvertedIndexList.cpp inverted_index/TownNode.cpp inverted_index/RecordPointer.cpp)
add_executable(OS_F14_Prj1 ${SOURCE_FILES})