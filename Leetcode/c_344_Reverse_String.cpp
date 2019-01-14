//
// Created by Mr.Hu on 2019/1/14.
//
// leetcode 344 reverse string
//
// 依次交换0～length-1，1～length-2，...，i~length-1-i，直到i=length/2；
//

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int length = s.length();
        for (int i = 0; i < length / 2; i++) {
            swap(s[i], s[length - 1 - i]);
        }
        return s;
    }
};

int main() {
    string s = "hello world!";
    Solution solution;
    string reverse_string = solution.reverseString(s);
    cout << s << endl;
    cout << reverse_string << endl;
    return 0;
}