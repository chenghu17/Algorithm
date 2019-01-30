//
// Created by Mr.Hu on 2019/1/30.
//
// leetcode 949 largest time for given digits
//
// 题目给定四个数字，要求利用这四个数，组成一个时间表示，"hh:mm"，使得该时间最大，如果无法组成，则返回""。
//
// 刚开始这个题目，以为只要逐个判断时钟第一位，第二位，分钟第一位，第二位，但是提交两次，错误case[2,0,6,6],[0,4,0,0]
// 后来重新想解决方法：对所有情况进行考虑，然后筛选出最大情况，而数字只有四个，所以很方便就可以得到所有情况，
// 利用四层嵌套循环，每一层表示一位，在循环中首先判断当前位置取值的合理性，或者是当前小时数/分钟数的有效性，
// 最后保留时间表示的分钟数，每次取当前最大的分钟数，最后将分钟数转换为题目要求的时间形式即可。
// 这种方式就不会遗漏一些情况。
// math类型的题目还是要懂一点小脑筋，有一些小的trick
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    string largestTimeFromDigits(vector<int> &A) {
        // 时钟：00-23 [0,1,2],[0,1,2,3]
        // 分钟：00-59 [0,1,2,3,4,5],[0,1,2,...,8,9]
        int time = 0;
        string res = "";
        bool has_largest = false;
        vector<int> hours;
        for (int i = 0; i < 4; i++) {
            if (A[i] > 2) {
                continue;
            }
            for (int j = 0; j < 4; j++) {
                if (i == j || A[i] * 10 + A[j] > 23) {
                    continue;
                }
                for (int m = 0; m < 4; m++) {
                    if (m == i || m == j || A[m] > 5) {
                        continue;
                    }
                    for (int n = 0; n < 4; n++) {
                        if (n == i || n == j || n == m || A[m] * 10 + A[n] > 60) {
                            continue;
                        }
                        has_largest = true;
                        time = max((A[i] * 10 + A[j]) * 60 + (A[m] * 10 + A[n]), time);
                    }
                }
            }
        }
        if (has_largest) {
            res += time / 60 < 10 ? "0" + to_string(time / 60) : to_string(time / 60);
            res += ":";
            res += time % 60 < 10 ? "0" + to_string(time % 60) : to_string(time % 60);
        }
        return res;
    }
};

int main() {
    vector<int> A = {2, 0, 6, 6};
    Solution solution;
    string res = solution.largestTimeFromDigits(A);
    cout << "the largest time : " << res << endl;
    return 0;
}