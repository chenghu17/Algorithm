//
// Created by Mr.Hu on 2018/4/26.
//
// leetcode 717 1-bit-and-2-bit-characters
//
// 昨天没有做题，下午去见导师然后去游泳去了，错过了校车只能做地铁回来，晚上又在改实验，今天多做几个题目。
// 先来说一下这个题目，这个题目要求对于给定的数组，数组的最后一位恒为0，数组中包含三种数，第一种是一个比特的0，
// 另一种是两个比特的10或11，然后现在对于数组中组成的串，用这三种数进行划分，判断最后一个是不是一个比特的0。
//
// 先来分析一下，既然要判断对数组进行表示后最后一个数能否为单独的0，那么最后一位之前的子串则可以完整被上面
// 说的三种数表示。分析如果导数第二位为0，那么有两种情况，一种是单独用0表示，另一种是倒数第三位为1，此时
// 不管如何，最后一位的0都可以被单独一个比特表示，但是如果倒数第二位为1，那么此时就要继续往前判断了，
// 通过草稿分析，从倒数第二位开始，往前遍历，到第一个为0处停止，如果中间存在奇数个1，则最后一位的0不能用
// 一个比特表示，只能和前面的1一起进行表示；如果中间存在偶数个1，则最后一位可以用一个比特来表示。
// 于是从后往前遍历，对中间1的个数进行遍历，最后判断中间1的个数的奇偶型即可。
//
// 思考：对于这种能够枚举出来的情况，在没有思路的时候可以在草稿纸上比划比划，找找规律。
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