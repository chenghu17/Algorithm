//
// Created by Mr.Hu on 2019/1/10.
//
// leetcode 400 Nth digit
//
// 题目要求对数字序列，1,2,3,4,...,10,11,...,100,101,...,按位取第n位的数字。
//
// 对于math的题目，最重要的步骤是找到其中潜在的关系；
// 经过观察，长度为1的数字有9个，长度为2的数字有90个，长度为3的数字有900个,...
// 那么当我们拿到数字n时，判断它是在哪个区间，所以就需要循环的去减去前面的区间，直到n剩下的个数在当前区间总数内。
//
// 这里有一个比较重要的trick，在while循环中，如果我们直接使用n-num_size*num_length>0，会出现当num_size和num_length都比较大时，
// 乘法的结果会超过int的范围，导致程序出错。
// 因此我们这里使用除法进行判断，但是如果单纯的使用n/num_size>num_length的关系，也会出错，例如n取11时，商为1，但是并不能进入循环内，
// 如果加上等于号，当n取9时，n就会变成0。
//
// 所以这里还有一个注意点，就是需要利用 n/(num_size+1)>length，在while内部还是利用n-num_size*length的方式，这就避免了当前值正好对应
// 当前区间的最后一个数字的情况。
//
// 这个题目虽然是easy级别的题目，还是需要点时间来完全解决。
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int num_length = 1; // 表示每个数字的长度
        int num_size = 9;   // 表示这个长度的数字总共有多少个

        while (n / (num_size + 1) >= num_length) {
            n -= num_length * num_size;
            num_length++;
            num_size *= 10;
        }

        int next = n % num_length;
        int num = n / num_length;
        if (next == 0) {
            num = num - 1;
            next = num_length;
        }

        int begin = num_size / 9;
        string cur_number = to_string(begin + num);

        return cur_number[next - 1] - 48;
    }
};

int main() {
    int n = 2147483647;
    Solution solution;
    int digit = solution.findNthDigit(n);
    cout << "the digit is " << digit << endl;
    return 0;
}