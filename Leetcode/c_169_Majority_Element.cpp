//
// Created by Mr.Hu on 2018/4/4.
//
// leetcode 169 Majority Element
// 题目给定一组数字，求众数(其实不是众数，可以理解为特殊的众数)，假设众数只有一个，且出现次数大于n/2。
// 这个题目很扯，需要找出现次数最多的数字，就想到用map的key-value来操作，
// key值为具体的element，value值为出现的次数。
// 于是想对所有数字遍历完后，来找出value最大值所对应的key，
// 但是由于对map不是很熟悉，所以在网上查了一些资料，发现要重写模板方法，懒得搞，
// 突然想到题目说Majority Element出现的次数要大于n/2，那我在进行遍历的时候就可以判断某个element的value值，
// 一旦大于n/2，则该element就是majority element，return出来就欧科了...
// submit之后，accepted了，哈哈哈，但是...我将代码copy到Clion下，map的find方法出现异常，指向不明...但是可以执行。
// 使用另外一种方法，count方法，element_map.count(element)，可以判断element是否出现，这里就是key值是否存在，输出1则说明存在，0则为不存在。
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        map<int, int> element_map;
        auto size = nums.size();
        if (size < 2) {
            return nums[0];
        }
        for (int i = 0; i < size; i++) {
            int element = nums[i];
            if (element_map.count(element) > 0) {
//            if (element_map.find(element) != element_map.end()) {
                element_map[element]++;
                if (element_map[element] > size / 2)
                    return element;
            } else {
                element_map[element] = 1;
            }
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 4, 4, 4};
    Solution solution;
    int element = solution.majorityElement(nums);
    cout << element << endl;
    return 0;
}