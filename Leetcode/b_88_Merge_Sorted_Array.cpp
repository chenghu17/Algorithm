//
// Created by Mr.Hu on 29/03/2018.
// leetcode 88 merge sorted array
// 这题看似比较容易，其实有一些坑在里面。怎么说呢，我觉得是题目表述不明。
// 刚开始我以为m和n分别表示nums1和nums2中element的数量，就想这个数量直接用vector.size()就可以得到，何必给出呢？
// 第一次提交后，发现m和n中有蹊跷，原来m和n表示用于合并的各自的元素数，即nums1的前m个和num2的前n个合并！
// 所以又对代码进行调整，在代码中使用了vector的内存清理方法，开始对empty()、clear()很模糊，查询后了解并进行记录：
// clear()表示对变量的元素进行清空，即此时size=0,但是其capacity还是不变；而empty()则是判断变量是否为空；
// 另外，vector之间的复制，不能直接使用赋值符号(=)，可以使用asign()或swap()，vector还有大量的属性，在学习c++ STL时系统学习
// 其实，leetcode在进行测试的时候，测试用例还不够完整，比如m=0，n=0，应该返回的是nums1.clear()，但是我之前并未对nums1进行clear()操作，还是accepted了
// 所以重新更正，重新提交，但是runtime居然更大了...
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (n == 0 && m == 0) {
            nums1.clear();
        } else {
            vector<int> tmp;
            tmp.assign(nums1.begin(), nums1.end());
            nums1.clear();
            int i = 0, j = 0;
            for (; i < m && j < n;) {
                if (tmp[i] <= nums2[j]) {
                    nums1.push_back(tmp[i]);
                    i++;
                } else {
                    nums1.push_back(nums2[j]);
                    j++;
                }
            }
            if (i < m) {
                for (; i < m; i++)
                    nums1.push_back(tmp[i]);
            }
            if (j < n) {
                for (; j < n; j++)
                    nums1.push_back(nums2[j]);
            }
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    vector<int> nums2 = {2, 3, 4};
    int m = 3, n = 0;
    Solution solution;
    solution.merge(nums1, m, nums2, n);
    vector<int>::iterator it;
    for (it = nums1.begin(); it < nums1.end(); it++) {
        cout << *it;
    }
    return 0;
}