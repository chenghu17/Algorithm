cmake_minimum_required(VERSION 3.9)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm tmp.cpp)

add_executable(Two_Sum Leetcode/Two_Sum.cpp)

add_executable(Remove_Duplicates Leetcode/Remove_Duplicates.cpp)

add_executable(Judge_Square InterviewQ/Judge_Square.cpp)

add_executable(Judge_Direction InterviewQ/Judge_Direction.cpp)

add_executable(Reverse_Integer Leetcode/Reverse_Integer.cpp)

add_executable(Remove_Element Leetcode/Remove_Element.cpp)

add_executable(Plus_One Leetcode/Plus_One.cpp)

add_executable(Insert_Position Leetcode/Insert_Position.cpp)

add_executable(Maximum_Subarray Leetcode/Maximum_Subarray.cpp)

add_executable(Palindrome_Number Leetcode/Palindrome_Number.cpp)
