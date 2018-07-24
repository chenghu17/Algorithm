//
// Created by Mr.Hu on 2018/7/24.
//
// leetcode 836 rectangle overlap
//
// 题目要求判读两个长方形是否存储重合部分，给定两个长方形的左下点和右上点的坐标。
//
// 这个题目的思想就是去寻找两个长方形满足重叠情况时坐标点的关系；
// 而如果直接去判断重叠条件是比较麻烦的，因为存在很多种情况，可以考虑相反情况，即两个长方形不重叠的情况。
// 两个长方形如果不重叠，即rec2在rec1的左边，右边，上边，下边这四种情况
// rec2在rec1的左边，则rec2.x2<=rec1.x1;
// rec2在rec1的右边，则rec2.x1>=rec1.x2;
// rec2在rec1的上边，则rec2.y1>=rec1.y2;
// rec2在rec1的下边，则rec2.y2<=rec1.y1;
// 不满足以上四种情况，则说明存在重复情况。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec2[2]<=rec1[0] || rec2[0]>=rec1[2] || rec2[1]>=rec1[3] || rec2[3]<=rec1[1]){
            return false;
        }
        return true;
    }
};

int main(){
    vector<int> rec1,rec2;
    rec1.emplace_back(0);
    rec1.emplace_back(0);
    rec1.emplace_back(1);
    rec1.emplace_back(1);
    rec2.emplace_back(1);
    rec2.emplace_back(0);
    rec2.emplace_back(2);
    rec2.emplace_back(1);
    Solution solution;
    bool isoverlap = solution.isRectangleOverlap(rec1,rec2);
    cout<<isoverlap<<endl;
    return 0;
}