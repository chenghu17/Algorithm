//
// Created by Mr.Hu on 2018/6/11.
//
// 随手科技笔试题2018
//
// 题目给定只包含正整数的数组，求前K个重复次数最多的数组，按照重复数字从小到大的顺序进行排列输出
//
// 这个题目其实在很多地方都会用到，像hadoop/spark中的word count也是相同的目标，在recommendation system中
// 对于 learning to rank的目标，最终都会要求求的top-n。
//
// 由于我还没有对特别复杂的数据结构了解，所以在这里使用了一些比较基础的数据结构来实现这样一个目标。
// 首先是将vector中的每个数字存储在map<int,int>这样一个数据结构中，key即为数值，value即为该数值出现的次数。
// 得到这样一个map之后，按道理来说答案就很明了，但是由于计算机并不能只能的输出top-k，所以我们还需要对map进行操作，
// 将其按照value进行排序，而这个排序并不能使用内置的sort()来进行，因为sort不支持对map进行排序，但是支持对vector
// 进行排序，所以想到将map转换为vector，而vector中存储的对象就是pair(int,int)，得到vector<pari(a,b)>之后，
// 我们可以使用sort对vector按照pair.second从大到小进行排序，这里就需要给sort方法的第三个参数cmp进行重写。
// 排序后的vector就是按照value值的大小从大到小进行排列，最后输出前k个vector的first值就可以了。
//
//
// 原来sort函数的cmp方法这么有效...需要深入的学习学习
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> find_Top_n_duplication(vector<int> arr, int n) {
        vector<int> result(n);
        map<int, int> tmp;
        auto size = arr.size();
        for (int i = 0; i < size; ++i) {
            int index = arr[i];
            tmp[index]++;
        }
        // 对map按照value值排序
        vector<pair<int, int>> vtMap;
        for (auto it = tmp.begin(); it != tmp.end(); it++)
            vtMap.push_back(make_pair(it->first, it->second));

        sort(vtMap.begin(), vtMap.end(),
             [](const pair<int, int> &x, const pair<int, int> &y) -> int {
                 return x.second > y.second;
             });
        int i = 0;
        for (auto it = vtMap.begin(); it != vtMap.end(); it++) {
            if (i < n) {
                result[i] = it->first;
                i++;
            } else {
                break;
            }
        }
        return result;
    }
};

int main() {
    vector<int> arr;
    int n = 5;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    Solution solution;
    vector<int> res = solution.find_Top_n_duplication(arr, n);
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
};