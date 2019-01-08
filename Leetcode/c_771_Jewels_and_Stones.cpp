//
// Created by Mr.Hu on 2019/1/8.
//

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewel;
        for (int i = 0; i < J.length(); i++) {
            jewel.insert(J[i]);
        }
        int count_jewel = 0;
        for (int i = 0; i < S.length(); i++) {
            if (jewel.count(S[i])) {
                count_jewel++;
            }
        }
        return count_jewel;
    }
};

int main() {
    string J = "aA";
    string S = "aabbccddA";
    Solution solution;
    int count = solution.numJewelsInStones(J, S);
    cout << "jewel count:" << count << endl;
    return 0;
}