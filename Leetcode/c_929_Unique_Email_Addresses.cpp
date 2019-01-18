//
// Created by Mr.Hu on 2019/1/18.
//
// leetcode unique email addresses
//
// 题目给定一些emails地址，规定@之前的部分称为local name，之后的称为domain name。
// 在local部分，如果出现'.'字符，忽略，如果出现'+'字符，包括该字符在内的之后所有字符全部忽略（local部分）
// 在domain部分，没有上述情况，即保持原状。要求给所有的emails发邮件，问会有多少个不同的邮箱收到邮件。
//
// 最基本的想法就是对每个email的local部分删除可以忽略的部分，形成最简email地址，最后判断存在多少个不同的最简地址。
// 首先，我们使用string.find('@')方法找到at的位置，这样可以抽离出local和domain。
// 对local部分进行遍历，得到最简local，然后将该local于domain进行拼接，存入set<string>中，
// 最后set的大小即为最简email地址的数量。
//
// 注：我这里是重新生成了最简email，也可以在原email部分，使用erase删除操作，去掉可以忽略的部分。
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string> &emails) {
        set<string> count;
        string local, domain, cur;
        int at_index;
        for (auto email:emails) {
            cur = "";
            at_index = email.find('@');
            local = email.substr(0, at_index);
            domain = email.substr(at_index, email.length() - at_index);

            for (int i = 0; i < local.length(); i++) {
                if (isalpha(email[i])) {
                    cur += email[i];
                } else if (email[i] == '.') {
                    continue;
                } else {
                    break;
                }
            }
            cur += domain;
            count.insert(cur);
        }
        return count.size();
    }
};

int main() {
    vector<string> emails = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
                             "testemail+david@lee.tcode.com"};
    Solution solution;
    int count = solution.numUniqueEmails(emails);
    cout << count << endl;
    return 0;
}