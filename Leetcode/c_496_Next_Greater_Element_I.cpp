//
// Created by Mr.Hu on 2019/1/21.
//
// leetcode 496 next greater element I
//
// 题目给定两个数组findNums和nums，findNums是nums的子集，要求找出findNums中每一个元素在nums中右边第一个比其大的元素，如果不存在，则为-1。
//
// 最直观的解法，对于findNums中的每一个元素，在nums中找到，然后记录第一个比其大的元素，如果不存在，则为-1，这也是下面代码中的第一种方法。
//
// 第二种方法，先对数组nums进行预处理，得到每个元素中第一个比其大的元素，用map进行存储，因为nums中元素不重复，可以当作key。
// 具体做法就是使用stack数据结构，将每个元素压入栈中，在压入之前，先循环判断栈顶元素与当前元素的大小关系，如果比当前元素小，则说明
// 栈顶元素右边第一个比其大的元素就是当前元素，于是用map记录，栈顶元素出栈，继续判断当前栈顶元素。
// 这个方法比较妙，用栈来初始化大小关系，值得学习。该方法即下面代码中的optimal
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
        if (!findNums.size()) {
            return findNums;
        }
        vector<int> res(findNums.size());
        bool find, has_bigger;
        for (int i = 0; i < findNums.size(); i++) {
            find = false;
            has_bigger = false;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == findNums[i]) {
                    find = true;
                } else if (nums[j] > findNums[i] && find) {
                    res[i] = nums[j];
                    has_bigger = true;
                    break;
                }
            }
            if (!has_bigger) {
                res[i] = -1;
            }
        }
        return res;
    }

    vector<int> nextGreaterElement_optimal(vector<int> &findNums, vector<int> &nums) {
        stack<int> stk;
        map<int, int> first_greater;
        for (auto num:nums) {
            while (!stk.empty() && stk.top() < num) {
                first_greater[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }

        vector<int> res;
        for (int i = 0; i < findNums.size(); i++) {
            if (first_greater.find(findNums[i]) != first_greater.end()) {
                res.push_back(first_greater[findNums[i]]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};

int main() {
    vector<int> findNums = {3, 1, 2};
    vector<int> nums = {1, 3, 5, 2, 9};
    Solution solution;
    vector<int> res = solution.nextGreaterElement(findNums, nums);
    vector<int> res_optimal = solution.nextGreaterElement_optimal(findNums, nums);
    for (auto i :res) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i :res_optimal) {
        cout << i << " ";
    }
    return 0;
}