cmake_minimum_required(VERSION 3.0)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

add_executable(bubble sorting/sort_bubble.cpp)
add_executable(merge sorting/sort_merge.cpp)
add_executable(count sorting/sort_counting.cpp)
add_executable(insertion sorting/sort_insertion.cpp)

add_executable(segtree segment_tree.cpp)

add_executable(vector_ data_structures/vector_.cpp)
add_executable(list data_structures/list.cpp)
add_executable(heap data_structures/priority_queue.cpp)