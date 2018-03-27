cmake_minimum_required(VERSION 3.9)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm tmp.cpp)

add_executable(Two_Sum Leetcode/Two_Sum.cpp)

add_executable(Remove_Duplicates Remove_Duplicates.cpp)

add_executable(Judge_Square Judge_Square.cpp)

add_executable(Reverse_Integer Reverse_Integer.cpp)

add_executable(Remove_Element Remove_Element.cpp)

add_executable(Plus_One Leetcode/Plus_One.cpp)

add_executable(Insert_Position Leetcode/Insert_Position.cpp)

add_executable(Maximum_Subarray Leetcode/Maximum_Subarray.cpp)
