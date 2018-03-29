//
// Created by Mr.Hu on 29/03/2018.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (n == 0 && m == 0) {
            nums1.clear();
        }
        else {
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