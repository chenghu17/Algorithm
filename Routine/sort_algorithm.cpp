//
// Created by Mr.Hu on 2019/2/19.
//
// 注意区分 插入排序 和 选择排序
// 注意 快速排序 的几个变量
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:

    // 冒泡排序：每次将最大值选择到之后的位置
    void bubble_sort(vector<int> &nums) {
        bool changed;   // 每次冒泡后判断是否已经有序，可提前结束循环
        for (int i = nums.size(); i > 0; i--) {
            changed = false;
            for (int j = 1; j < i; j++) {
                if (nums[j]<nums[j-1]){
                    swap(nums[j],nums[j-1]);
                    changed = true;
                }
            }
            if(!changed){
                break;
            }
        }
    }

    // 选择排序：每次选择最小的值放在最前面
    void choose_sort(vector<int> &nums){
        int min_num,min_idx;
        for(int i=0;i<nums.size();i++){
            min_num = nums[i];
            min_idx = i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<min_num){
                    min_num = nums[j];
                    min_idx = j;
                }
            }
            swap(nums[i],nums[min_idx]);
        }
    }

    // 插入排序：每次将待排序的值与前面已经排序的值进行比较，比前面的值小，则交换继续与前面的比较，否则当前位置即合适的位置
    void insert_sort(vector<int> &nums){
        for(int i=1;i<nums.size();i++){
            for(int j=i;j>0;j--){
                if(nums[j]<nums[j-1]){
                    swap(nums[j],nums[j-1]);
                }
            }
        }
    }

    // 希尔排序

    // 归并排序

    // 快速排序 in-place
    int partition(vector<int> &nums, int low, int high) {
        int tmp = nums[low];
        // 判断是否进行了数据交换，如果不存在，则说明后面的数据都要比第一个数据大，
        // 但是后面是否有序并不知道，所以需要返回low+1；
        // 而如果进行了交换，low的位置必然是左边比原第一位小，右边大于等于原第一位。
        bool changed = false;
        while (low < high) {
            // 从左到右找到第一个大于等于tmp的数字
            while (low < high && nums[low] < tmp) {
                low++;
            }
            // 必须有一个等号判断
            while (low < high && nums[high] >= tmp) {
                high--;
            }
            if (low < high) {
                swap(nums[low], nums[high]);
                changed = true;
            }
        }

        return changed ? low : low + 1;
    }

    void quick_sort(vector<int> &nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = partition(nums, low, high);
        quick_sort(nums, low, mid - 1);
        quick_sort(nums, mid, high);
    }

    void quick(vector<int> &nums) {
        int size = (int) nums.size();
        if (size < 2) {
            return;
        }
        quick_sort(nums, 0, size - 1);
    }


    // 堆排序

    // 计数排序

    // 桶排序

    // 基数排序
};

int main() {
    vector<int> nums1 = {6, 3, 1, 8, 3, 9, 3, 4, 6, 2, 8};
    vector<int> nums2 = {1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 10};
    vector<int> nums3 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> nums4 = {1, 3, 2, 1};

    Solution solution;
//    solution.quick(nums);
//    solution.bubble_sort(nums2);
//    solution.choose_sort(nums4);
    solution.insert_sort(nums3);
    for (auto i:nums2) {
        cout << i << " ";
    }
    return 0;
}

