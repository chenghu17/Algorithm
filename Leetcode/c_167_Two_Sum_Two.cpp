//
// Created by Mr.Hu on 2018/4/4.
//
// leetcode 167 Two Sum two
// 题目给出升序数列，以及目标值，要求输出两个数的索引值，这两个数的和即为目标值，
// 且第一个值的索引值比第二个值的索引值小，并且要求数列中的每个数只能使用一次。且不考虑无解情况。
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> index;
        int size = numbers.size();
        int index1 = 0, index2 = size - 1;
        for (; index1 < index2;) {
            int result = numbers[index1] + numbers[index2];
            if (result == target) {
                index.push_back(index1 + 1);
                index.push_back(index2 + 1);
                break;
            }
            if (result < target) {
                index1++;
            } else {
                index2--;
            }
        }
        return index;
    }
};

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 17;
    Solution solution;
    vector<int> index = solution.twoSum(numbers, target);
    vector<int>::iterator it;
    for (it = index.begin(); it < index.end(); it++) {
        cout << *it << endl;
    }
}