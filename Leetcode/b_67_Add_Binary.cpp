//
// Created by Mr.Hu on 2018/5/25.
//
// leetcode 67 add binary
//
// 题目要求对两个二进制数求和
//
// 二进制的加法我们都知道，满二进一。由于两个二进制数使用string来表示。
// 这里主要还是考察对string类的用法以及二进制加法逻辑结构的实现。
//
// 首先在加法逻辑结果上，我们都知道，先低位相加，然后依次迭代到高位，最后完成加法运算。
// 现在这里存在这样一个问题：两个二进制数的位数不一样，那么势必又一个数会先迭代完，然后另外
// 一个数剩下的部分得继续进行运算然后将结记录在最后的result变量中。
//
// 所以我们这里就随便选择了a作为第一个加数，b为第二个加数。在加第二个加数时，需要判断该加数是否迭代完；
// 如果第二个加数迭代完，则后续操作只是对a剩下的高位进行运算，如果没有迭代完，则两个数进行常规加操作。
// 当a迭代完后，由于我们刚开始是随机选择的一个数作为第一个加数，所以有可能在a迭代完之后，b还存在高位没有迭代完。
// 所以我们要继续进行判断b的位数，如果没有迭代完，则单独对b进行加操作。这样实现下来符合从低位到高位的运算逻辑。
//
// BUG One:
// running之后出现了一个问题，"11"和"1"相加得到"10"，
// 原因在于我判断两个数相加如果等于2，则直接result = "10"+result；这样不对在于进位是需要加在高位伤的，我这样就相当于写死了。
// 所以我加了一个int up; 来保留进位，然后在每次计算高位时将进位也一起加进去判断。
//
// BUG Two:
// 解决了BUG One之后，我继续running，此时"1111"与"1111"加法出错，
// 原因在于我刚开始判断两个数对应位置相加时，我错误的认为两个位数相加最多只能为2，其实考虑进位，最多会是3。
// 因此在判断两个数相加的结果时，我将原谅的if(tmp==2)改成了if(tmp>=2)，而后面的操作也改成了：
// result = to_string(tmp%2) + result;
//
// 再次running，accepted，但是看了一下运行效率，只超过了三分之一的提交结果...
//
//

#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int index_a = a.length() - 1;
        int index_b = b.length() - 1;
        string result = "";
        int up = 0;
        // int size = min(size_a,size_b);
        while (index_a >= 0) {
            if (index_b >= 0) {
                int tmp = int(a[index_a] - '0') + int(b[index_b] - '0') + up;
                if (tmp >= 2) {
                    result = to_string(tmp % 2) + result;
                    up = 1;
                } else {
                    result = to_string(tmp) + result;
                    up = 0;
                }
                index_a--;
                index_b--;
            } else {
                // break;
                int tmp = int(a[index_a] - '0') + up;
                if (tmp == 2) {
                    result = "0" + result;
                    up = 1;
                } else {
                    result = to_string(tmp) + result;
                    up = 0;
                }
                index_a--;
            }
        }
        while (index_b >= 0) {
            int tmp = int(b[index_b] - '0') + up;
            if (tmp == 2) {
                result = "0" + result;
                up = 1;
            } else {
                result = to_string(tmp) + result;
                up = 0;
            }
            index_b--;
        }
        if (up != 0) {
            result = to_string(up) + result;
        }
        return result;
    }
};

int main(){
    string a = "1111";
    string b = "1111";
    Solution solution;
    string result = solution.addBinary(a,b);
    cout<<result<<endl;
    return 0;
}