//
// Created by Mr.Hu on 2018/6/2.
//
// leetcode 171 excel sheet column number
//
// 题目要求将excel中表示行的字符串转换为对应的数字：规则为A->1,...,Z->26,AA->27，AB->28
//
// 更加规则可以得到，这其实就是将一个26进制的数转换为10进制的数字，其中26进制数的每一位是用大写字母来表示。但也是存在与数字的对应关系。
// 直到了26进制这一关系，接下来我们要做的就是将字母转换为数字，而这里就想到其实每个字母在计算机环境下是存在一个数字表示的，即ASCII码。
// 所以我们现在需要从string中提取char，根据之前的经验，s[i]-'\0'即可得到相应的字母，其与数字进行计算则默认转换为其ASCII码。
// 值得注意的是，转换成ASCII码之后，与其在excel中所表示的数字还是存在一个常量差值，即A的ASCII为65，在excel中表示1，差值即为64。
// 而ASCII码的递增情况和excel中的递增情况一样，都是以一为单位递增。所以我们在得到每一个字母的ASCII码之后，减去64即转换为该字母在excel中所对应的数字。
//
// 找出了进制关系，并得到了每个字母在excel中对应数字的提取办法，剩下的就是对每个字母进行遍历，乘以进制关系，然后累加。
//

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int length = s.size();
        int result = 0;
        for (int i = 0; i < length; i++) {
            int tmp = s[i] - '\0' - 64;
            result += tmp * pow(26, (length - i - 1));
        }
        return result;
    }
};

int main() {
    string s = "ABCD";
    Solution solution;
    int result = solution.titleToNumber(s);
    cout << result << endl;
    return 0;
}