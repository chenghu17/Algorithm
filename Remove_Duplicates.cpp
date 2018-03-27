//
// Created by Mr.Hu on 22/03/2018.
// Remove Duplicates from Sorted Array
// 从已经排序的数组中删除重复值，要求空间复杂度为O(1)
// 在原数组中进行更替，前index个数组都为非重复的，返回index的值

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums);

int main() {
    vector<int> nums = {1, 1, 1, 1, 1, 2, 3, 4, 4, 4, 4, 5};
    int index = removeDuplicates(nums);
    cout << index << endl;
    for (int i = 0; i < index; i++) {
        cout << i << ":" << nums[i] << endl;
    }
    return 0;

}

int removeDuplicates(vector<int> &nums) {
    int size = int(nums.size());
    if (size < 2)
        return size;
    int index = 1;  //先默认保留数组的第一个数字
    for (int i = 1; i < size; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[index] = nums[i];
            ++index;
        }
    }
    return index;
}