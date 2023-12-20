cmake_minimum_required(VERSION 3.27)
project(LargeInt)

set(CMAKE_CXX_STANDARD 17)

add_executable(LargeInt main.cpp
        DoublyLinkedList.h
        DoublyLinkedList.cpp
        LargeInt.cpp
        LargeInt.h)
