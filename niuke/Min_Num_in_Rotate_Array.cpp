//
// Created by Mr.Hu on 2019/9/6.
//
// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
// NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
//
// 思路：将数组中所有点放进二维坐标轴中，最小值应该是波谷
// 需要注意的是，由于原数组为非递减排序，这就意味着存在重复值，而重复值的出现就需要我们额外的去小心等号条件
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        auto array_size = rotateArray.size();
        if (array_size == 0) {
            return 0;
        }
        if (array_size == 1 || array_size == 2) {
            return rotateArray[array_size - 1];
        }
        int index = 1;
        int min_num = INT_MAX;
        for (; index < array_size - 1; ++index) {
            if (rotateArray[index - 1] >= rotateArray[index] && rotateArray[index + 1] > rotateArray[index]) {
                min_num = min(min_num, rotateArray[index]);
            } else if (rotateArray[index - 1] > rotateArray[index] && rotateArray[index + 1] >= rotateArray[index]) {
                min_num = min(min_num, rotateArray[index]);
            } else if (rotateArray[index - 1] >= rotateArray[index] && rotateArray[index + 1] >= rotateArray[index]) {
                min_num = min(min_num, rotateArray[index]);
            }
        }
        // 考虑最小值在最后一位
        if (rotateArray[array_size - 1] < rotateArray[array_size - 2]) {
            min_num = min(min_num, rotateArray[array_size - 1]);
        }
        return min_num;
    }
};

int main() {
    vector<int> rotateArray = {3, 4, 5, 1, 1, 2, 2, 3};
    Solution solution;
    int min_num = solution.minNumberInRotateArray(rotateArray);
    cout << min_num << endl;
    return 0;
}