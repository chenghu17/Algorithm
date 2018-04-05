//
// Created by Mr.Hu on 2018/4/5.
//
// leetcode 219 contains duplicate two
// 这一题可以说是一次滑铁卢了...提交了六次，终于accepted了...
// code中给出了两种方法，第一种方法我提交了四次，开始是重复使用iterator，导致runtime error
// 然后把循环条件改成size()之后，23组test cases过了22组，但是就是报time limit exceeded，
// 都说leetcode的时间复杂度限制很松，一般出现这种情况都是死循环导致的，我仔细的找了一下，发现一定不存在死循环。
// 心累，就觉得这次可能真的是时间复杂度太高了。
//
// 于是上网查了一下，发现可以使用217中的想法，继续使用map进行存储，然后比较index的差值
// 对于两个相等，但是index数超过目标k时，map的value值就要更新为较大的index，毕竟越往后，与前面的index值越远
// 多思考，尽量不用蛮力法...
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] == nums[j]) {
                    int difference = j - i;
                    if (difference <= k) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool containsNearbyDuplicate_optimal(vector<int> &nums, int k) {
        map<int, int> element;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            if (element.count(nums[i]) > 0) {
                int difference = i - element[nums[i]];
                if (difference <= k) {
                    return true;
                }
                    // update
                else {
                    element[nums[i]] = i;
                }
            } else {
                element[nums[i]] = i;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 2};
    int k = 5;
    Solution solution;
    bool result = solution.containsNearbyDuplicate_optimal(nums, k);
    cout << result << endl;
    return 0;
}