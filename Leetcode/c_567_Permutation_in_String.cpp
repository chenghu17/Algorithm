//
// Created by Mr.Hu on 2018/8/27.
//
// leetcode 567 permutation in string
//
// 题目要求对于字符串s1和s2，判断s2中是否存在子串，是字符串s1的变体，如果是则返回true，否则返回false
//
// 根据题目规定，字符串中只存在小写字母，则说明只有26个字符出现，所以我们可以使用数组将字符串s1中字符出现的情况进行保存。
// 然后对s2中子串出现的情况筛选，并且与模式串s1进行比较；
// 如果s2中出现了s1中从未出现的字符，则内循环结束，i从i+j+1开始，即从未出现的字符的下一位开始
// 如果s2子串中出现的字符都在s1中出现过，则循环length1次之后，则可以开始判断两个子串中字符出现次数的情况。
// 如果相同，则返回true，否则i的值+1，即从i的下一个数开始继续循环遍历。
//
// 这种方法有点蛮力，虽然在s2中出现s1未出现字符时，不是从i的下一位继续循环，但是整个循环过程比较复杂
//
// 使用leetcode上推荐的一个解法，即下面的第二种方法：
// 用数组保留s1中各字母出现的次数，然后用两个指针(这里其实就是index值)
// ptr1<length2，将s1[ptr1]所对应的字母在s1字母出现次数数组中减减，如果减1后值小于0，则说明该字母出现次数过多，
// 则从ptr2开始往ptr1推，每次取ptr2指向的字符并在数组中++，直到数组中小于0的那位不再小于0，则停止移动ptr2，
// 此时判断ptr1与ptr2之间的距离，如果正好等于length1，则说明该子串就是s1的变体，否则对ptr1++继续上述循环。
// 这种解法比较新颖，而且不难看出需要一定的算法功底。
// 其解决的主要问题就是在对s1对应的数组进行--之后，值小于0，如何"回溯"的问题。小于0则说明当前子串不能满足为s1的变体。
// 如果小于0的字符在s1中出现过，移动ptr2则可以把之前多的剔除，继续循环向后，则无需回到i++的位置；
// 如果小于0的字符未在s1中出现，那么此时移动ptr2到ptr1才会终止，这也符合我们的要求。
//

#include <iostream>
using namespace std;

class Solution {
public:
    // 用一个数组存在s1中所有的字符
    bool checkInclusion(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();

        if (length1 > length2) {
            return false;
        }

        int tmp1[26] = {0};
        int tmp2[26] = {0};
        // 存储模式串中每个字符出现的次数
        for (int i = 0; i < length1; ++i) {
            ++tmp1[s1[i] - 97];
        }

        bool issame = true;
        bool isright = true;
        for (int i = 0; i <= length2 - length1;) {
            for (int j = 0; j < length1; ++j) {
                if (tmp1[s2[i + j] - 97] == 0) {
                    i = i + j + 1;
                    memset(tmp2, 0, sizeof(tmp2));
                    issame = false;
                    break;
                }
                ++tmp2[s2[i + j] - 97];
            }
            if (!issame) {
                issame = true;
                continue;
            }
            for (int m = 0; m < 26; ++m) {
                if (tmp1[m] != tmp2[m]) {
                    ++i;
                    isright = false;
                    break;
                }
            }
            if (!isright) {
                memset(tmp2, 0, sizeof(tmp2));
                isright = true;
                continue;
            }
            return true;
        }
        return false;
    }


    bool checkInclusion_optimal(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();
        if(length1>length2){
            return false;
        }
        int charcount[26];
        for (int i = 0; i < length1; ++i) {
            ++charcount[s1[i] - 97];
        }
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < length2) {
            int index = s2[ptr1] - 97;
            charcount[index] -= 1;
            while (charcount[index] < 0) {
                int pindex = s2[ptr2]-97;
                ++charcount[pindex];
                ++ptr2;
            }
            if(ptr1-ptr1+2==length1)
                return true;
            ++ptr1;
        }
        return false;
    }
};

int main(){
    string s1 = "ab",s2="daiemsbbac";
    Solution solution;
    bool result = solution.checkInclusion_optimal(s1,s2);
    cout<<result<<endl;
    return 0;
}