//
// Created by Mr.Hu on 2019/9/6.
//
// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
//
// 可以用递归的思想来考虑，本质上就是斐波拉契数列问题，解法相同
//

#include <iostream>

using namespace std;

class Solution {
public:
    int rectCover(int number) {
        if (number < 0) {
            return 0;
        }
        if (number < 3) {
            return number;
        }
        number -= 2;
        int first = 1, second = 2, cur = 0;
        while (number > 0) {
            cur = first + second;
            first = second;
            second = cur;
            --number;
        }
        return cur;
    }
};

int main() {
    int number;
    cin >> number;
    Solution solution;
    int res = solution.rectCover(number);
    cout << res << endl;
    return 0;
}