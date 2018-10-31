cmake_minimum_required(VERSION 3.12)
project(LeftistHeap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LeftistHeap
        double.in.txt
        double.out.txt
        ece250.h
        Exception.h
        int.in.txt
        int.out.txt
        Leftist_heap.h
        Leftist_heap_double_driver.cpp
        Leftist_heap_int_driver.cpp
        Leftist_heap_tester.h
        Leftist_node.h
        Tester.h)
