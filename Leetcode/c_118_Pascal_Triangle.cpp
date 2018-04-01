//
// Created by Mr.Hu on 2018/3/31.
//
// leetcode 118 Pascal's Triangle
// 这一题就是有名的帕斯卡三角形，也叫杨辉三角形（高中数学应该都听说过）
// 在解决这一题时，刚开始并没有想到能够使用二维vector进行操作，编译栏给了点提示。
// 然后进行编码时，发现每行的第一和最后一个数都是1，并且当前行的数字个数与行数相同，当前行与上一行存在着关系
// 所以想到使用嵌套循环，第一层表示当前为第几行，第二层为了去计算当前行的每个数字值是多少。
// 首先考虑特殊情况，第一行和第二行，以及每行的第一个和最后一个数字，然后再考虑中间数字与上一行数字的关系。
// 在代码中使用tmp来保存当前行的值，没计算完一行，则需要对tmp进行释放。使用来两种方式，发现都可以
// 1、vector<int> tmp;tmp.clear(); 2、vector<int> tmp;vector<int>().swap(tmp);
// 第一种是对tmp中的内容进行清空，但是capacity还存在；第二种就是capacity也为0，下次使用tmp需要重新声明。

// 问题一：Time Limit Exceeded
// solution:第二个for循环的j++写成了i++
// 问题二：reference binding to null pointer of type 'value_type'
// solution: int sum = result[i-2][j-1]+result[i-2][j];代码中，i-2写成了i-1;
//           原因在于为了让嵌套循环能够执行，在第一层循环中初始化i=1，这样j就可以方便的与i进行比较来判断当前行的状态
//           但是在下一行需要使用上一行数据时，直接使用i-1进行提取出现了问题，由于vector下标是从0开始的，而我此时设置i=1开始
//           因此如果用i-1，所指向的还是当前行，因此报空指针错误，改为i-2就是正常的读取前一行的数据。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
//        vector<int> tmp;
        for(int i=1;i<=numRows;i++){
            vector<int> tmp;
            for(int j=0;j<i;j++){
                if(j==0 || j==i-1){
                    tmp.push_back(1);
                }
                else{
                    int sum = result[i-2][j-1]+result[i-2][j];
                    tmp.push_back(sum);
                }
            }
            result.push_back(tmp);
//            tmp.clear();
            vector<int>().swap(tmp);
        }
        return result;
    }
};

int main(){
    int numRows = 5;
    Solution solution;
    vector<vector<int>> result = solution.generate(numRows);
    return 0;
}