//
// Created by Mr.Hu on 2019/1/21.
//
// leetcode 401 binary watch
//
// 题目给定一个场景：一只二进制表，上排有四个LED灯，分别表示1，2，4，8；下排有六个LED灯，分别表示1，2，4，8，16，32；
// 上排亮的LED构成当前时间的小时数，下排亮的LED构成当前时间的分钟数；
// 如果某一排灯不亮，则表示为0时/0分。现在给定表盘亮的LED灯总数，求出所有可能的时间数。
//
// 这个题目属于回溯法范畴，我对于这个方法并没有什么概念，所以去查了一下这个方法：
// 回溯法其实就是对隐式图的深度优先搜索，基本思路：
// 1、确定问题的解空间；2、确定结点的扩展规则；3、以深度优先方式搜索解空间，并在搜索过程中用剪枝函数避免无效搜索。
//
// 问题的解空间，就是所有的时间组合，而扩展规则就是小时数在[0,11]，分钟数在[0,59]，且时钟的组合来源于[1,2,4,8],
// 分钟的组合来源于[1,2,4,8,16,32].
// 基本的情况定义出来，但是在编码上还是一头雾水，后来看了discussion中一个java解答，觉得很清晰，便以这种方法进行了编码：
//
// 对于给定的num个LED亮着的灯，时钟的选择和分钟的选择都以及明确，无非就是选与不选的问题，而每一次选择的整体结构是相同的，
// 只要最后满足LED灯数为num即可，递归方式，即深度优先搜索，dfs(num,hour,minute,cur_h,cur_m)。
// 上述方法参数的含义：num表示当前还需要亮多少LED灯，hour表示当前可以选择上排LED灯的位置，minute表示当前可以选择下排LED灯的位置；
// cur_h和cur_m则表示当前已经累计的小时数和分钟数。
//
// 递归的主体：首先是当前已经累计的小时数和分钟数都要在正常范围内，即小时数为[0,11]，分钟数为[0,59],
// 然后就是判断还剩的LED灯数，如果为0，则表示当前累计的小时数和分钟数正好满足题目规定亮的LED灯数。
// 如果还不满足，则判断当前小时数是否还有的选，即hour的位置是否<4，因为只有四个上排LED，如果满足，则对于时钟有两种情况，
//      第一种就是选择该时钟，此时num-1，hour+1，cur_h需要累计top[hour]；
//      第二种就是不选择该时钟，此时num不变，hour+1，cur_h不变；
// 如果时钟已经选择完毕，则判断当前分钟数是否还有的选，即minute是否<6，因为只有六个下排LED，
// 如果满足，则对于分钟也有上述两种情况，只是更新的是分钟
//
// 这就是整个递归方法，这种方法可以说足够清晰。
//
// 另外还有人将上排四个LED灯亮0个，1个，2个，3个所能组成的小时数分类，对于分钟同样，
// 这样当给定num时，只要进行嵌套循环遍历，然后进行组合即可。这种方式也比较有趣。
//
// leetcode中100%的答案是下面optimal的这种，对于解空间中的每一个值，判断num个LED灯能否得到该值，而具体的判断方法是用基于位运算的方法。
// 题目是二进制手表，即我们可以将每个时间看作是一个10位的二进制数，前四位表示小时数，后六位表示分钟数，
// 给定num就相当于给定10位二进制数中存在多少个1，而传入小时和分钟数，判断总共的1个数是否和num数相等，则可以判断当前这个时间是否属于最终的结果。
// 这个方法对解空间中所有的值进行显示判断，也很高效，但是对位运算需要很熟悉。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<string> res;
    int top[4] = {1, 2, 4, 8};
    int bottom[6] = {1, 2, 4, 8, 16, 32};

    void dfs(int num, int hour, int minute, int cur_h, int cur_m) {
        // top最多3个灯亮
        // bottom最多5个灯亮
        if (cur_h > 11 || cur_m > 59) {
            return;
        } else if (num == 0) {
            // 表示当前有num个LED亮
            cur_m < 10 ? res.push_back(to_string(cur_h) + ":0" + to_string(cur_m)) : res.push_back(
                    to_string(cur_h) + ":" + to_string(cur_m));
        } else if (hour < 4) {
            // 当前hour不加入
            dfs(num, hour + 1, minute, cur_h, cur_m);
            // 当前hour加入
            dfs(num - 1, hour + 1, minute, cur_h + top[hour], cur_m);
        } else if (minute < 6) {
            // 当前minute加入
            dfs(num - 1, hour, minute + 1, cur_h, cur_m + bottom[minute]);
            // 当前minute不加入
            dfs(num, hour, minute + 1, cur_h, cur_m);
        }
        return;
    }

    vector<string> readBinaryWatch(int num) {
        if (num > 8) {
            return res;
        }
        dfs(num, 0, 0, 0, 0);
        return res;
    }

    vector<string> readBinaryWatch_optimal(int num) {
        vector<string> result;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (num == checkDigit(i, j)) {
                    if (j < 10) {
                        result.push_back(to_string(i) + ":0" + to_string(j));
                    } else {
                        result.push_back(to_string(i) + ":" + to_string(j));
                    }
                }
            }
        }
        return result;
    }

    int checkDigit(int hour, int minute) {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            if ((hour >> i) & 1 == 1) {
                count++;
            }
        }
        for (int i = 0; i < 6; i++) {
            if ((minute >> i) & 1 == 1) {
                count++;
            }
        }
        return count;
    }

};

int main() {
    Solution solution;
    vector<string> res = solution.readBinaryWatch(1);
    vector<string> res_optimal = solution.readBinaryWatch_optimal(1);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : res_optimal) {
        cout << i << " ";
    }
    return 0;
}