cmake_minimum_required(VERSION 3.9)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm tmp.cpp)

add_executable(Two_Sum Leetcode/a_1_Two_Sum.cpp)

add_executable(Remove_Duplicates Leetcode/b_26_Remove_Duplicates.cpp)

add_executable(Judge_Square InterviewQ/Judge_Square.cpp)

add_executable(Judge_Direction InterviewQ/Judge_Direction.cpp)

add_executable(Reverse_Integer Leetcode/a_7_Reverse_Integer.cpp)

add_executable(Remove_Element Leetcode/b_27_Remove_Element.cpp)

add_executable(Plus_One Leetcode/b_66_Plus_One.cpp)

add_executable(Insert_Position Leetcode/b_35_Insert_Position.cpp)

add_executable(Maximum_Subarray Leetcode/b_53_Maximum_Subarray.cpp)

add_executable(Palindrome_Number Leetcode/a_9_Palindrome_Number.cpp)

add_executable(Merge_Sorted_Array Leetcode/b_88_Merge_Sorted_Array.cpp)

add_executable(Pascal_Triangle Leetcode/c_118_Pascal_Triangle.cpp)

add_executable(Pascal_Triangle_two Leetcode/c_119_Pascal_Triangle_two.cpp)

add_executable(Buy_Sell_Stock Leetcode/c_121_Buy_Sell_Stock.cpp)


