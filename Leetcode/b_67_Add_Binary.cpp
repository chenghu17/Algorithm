//
// Created by Mr.Hu on 2018/5/25.
//
// leetcode 67 add binary
//
//
//



#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int index_a = a.length() - 1;
        int index_b = b.length() - 1;
        string result = "";
        int up = 0;
        // int size = min(size_a,size_b);
        while (index_a >= 0) {
            if (index_b >= 0) {
                int tmp = int(a[index_a] - '0') + int(b[index_b] - '0') + up;
                if (tmp >= 2) {
                    result = to_string(tmp % 2) + result;
                    up = 1;
                } else {
                    result = to_string(tmp) + result;
                    up = 0;
                }
                index_a--;
                index_b--;
            } else {
                // break;
                int tmp = int(a[index_a] - '0') + up;
                if (tmp == 2) {
                    result = "0" + result;
                    up = 1;
                } else {
                    result = to_string(tmp) + result;
                    up = 0;
                }
                index_a--;
            }
        }
        while (index_b >= 0) {
            int tmp = int(b[index_b] - '0') + up;
            if (tmp == 2) {
                result = "0" + result;
                up = 1;
            } else {
                result = to_string(tmp) + result;
                up = 0;
            }
            index_b--;
        }
        if (up != 0) {
            result = to_string(up) + result;
        }
        return result;
    }
};

int main(){
    string a = "1111";
    string b = "1111";
    Solution solution;
    string result = solution.addBinary(a,b);
    cout<<result<<endl;
    return 0;
}