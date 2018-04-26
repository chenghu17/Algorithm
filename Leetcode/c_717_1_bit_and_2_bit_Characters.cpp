//
// Created by Mr.Hu on 2018/4/26.
//
// leetcode 717 1-bit-and-2-bit-characters
//
//
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        int size = bits.size();
        int oneNumber = 0;
        for (int i = size - 2; i >= 0; i--) {
            if (bits[i] == 0) {
                break;
            } else {
                oneNumber++;
            }
        }
        if (oneNumber % 2 == 0) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    vector<int> bits = {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0};
    Solution solution;
    bool result = solution.isOneBitCharacter(bits);
    cout << result << endl;
    return 0;
}