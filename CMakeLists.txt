cmake_minimum_required(VERSION 3.0)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(bubble sort_bubble.cpp)
add_executable(merge sort_merge.cpp)
add_executable(count sort_counting.cpp)
add_executable(insertion sort_insertion.cpp)
add_executable(segtree segment_tree.cpp)