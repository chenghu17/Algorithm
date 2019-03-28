//
// Created by Mr.Hu on 2019/3/22.
//
// 快速排序，始终以index作为第一个大于标示节点的位置，一旦比标示节点的值小，则与index进行交换，
// 最后index指向的位置应该是第一个比标示位置大的点，则index-1与标示位置，并返回index-1即可。
//

#include <iostream>
#include <vector>

using namespace std;


int partition(vector<int> &nums, int l, int r) {
    int pivol = nums[l];
    int index = l+1;
    for(int i=l+1;i<=r;i++){
        if(nums[i]<pivol){
            swap(nums[index],nums[i]);
            index++;
        }
    }
    swap(nums[l],nums[index-1]);
    return --index;
}

void QuickSort(vector<int> &nums, int start, int end) {
    if (start >= end) {
        return;
    }
    // 找到中间划分的节点index
    int idx = partition(nums, start, end);
    QuickSort(nums, start, idx - 1);
    QuickSort(nums, idx + 1, end);
}


int main() {
    vector<int> nums = {4, 2, 5, 7, 3, 2, 5};
    QuickSort(nums, 0, nums.size() - 1);
    for (auto i:nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}