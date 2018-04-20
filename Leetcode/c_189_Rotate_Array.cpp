//
// Created by Mr.Hu on 2018/4/20.
//
// leetcode 189 rotate array
// 题目要求对给定n个元素的数组进行翻转(轮换)k次，
// 即每次将最后一个位置的数字防止第一位，其他的数字往后顺移。
//
// 第一种想法就是最暴力的方法，每次取最后一位，其他位向后顺移后，将之前取的最后一位赋值给第一位；
// 这种方法的时间复杂度为O(kn)，空间复杂度为O(1)，我第一见到leetcode不是
// 因为死循环而报Time Limit Exceeded的错误。
//
// 然后想到第二种方法，就是以下code中实现的思想。
// 观察发现，对于n个元素翻转k次，其实n次翻转则可以得到原数组，
// 所以我们只需要翻转k%n次就可以得到翻转k次相同的结果。
// 现在k%n是一定小于n，所以为了得到结果，我们只需要将[size-m,size-1]保存在新的vector中，
// 将[0,size-m-1]往后移动，使得[size-m-1]移动到[size-1]，[0]移动到[m]。
// 然后再将新的vector的元素赋值为原数组的[0,m-1]即可，最终的数组即为所求。
//
// 在网上查了一下，还有另外一种解法，对于[1,2,3,4,5,6,7]翻转k=3次，我们只需要将原数组翻转
// 得到[7,6,5,4,3,2,1],然后再将[0,k-1]翻转，再将[k,size-1]翻转则可得到所求。
// 这种方法可以说是看的长远，先不管要翻转多少次，总之是要翻转的，
// 对所有数字进行翻转，又因为题目的这种顺移
// 还是满足子数组从小到大的顺序排列的，所以对前k个再进行翻转，
// 得到从小打大排序，后面size-k个再进行翻转，得到从小到大排序。即为所求
// 这种思想值得学习，要训练出能够很快想到这种方法。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int size = nums.size();
        int m = k % size;
        vector<int> rotateArray;
        for (int i = size - m; i < size; i++) {
            rotateArray.push_back(nums[i]);
        }
        for (int j = size - m - 1; j >= 0; j--) {
            nums[j + m] = nums[j];
        }
        for (int n = 0; n < m; n++) {
            nums[n] = rotateArray[n];
        }

        // Time Limit Exceeded
        // int size = nums.size();
        // for(int i=1;i<=k;i++){
        //     int tmp = nums[size-1];
        //     for(int j=size-1;j>0;j--){
        //         nums[j] = nums[j-1];
        //     }
        //     nums[0] = tmp;
        // }
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 4;
    Solution solution;
    solution.rotate(nums, k);
    auto it = nums.begin();
    while (it != nums.end()) {
        cout << *it << ' ';
        it++;
    }
    return 0;
}