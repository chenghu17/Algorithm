//
// Created by Mr.Hu on 28/03/2018.
//


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> line;
        if (x < 0)
            return false;
        while (x != 0) {
            int tmp = x % 10;
            line.push_back(tmp);
            x /= 10;
        }
        int size = line.size() - 1;
        int tag = size / 2;
        for (int i = 0; i < tag; i++) {
            if (line[i] == line[size - i])
                continue;
            else
                return false;
        }
        return true;
    }

    bool isPalindrome_criterion(int x) {
        if (x < 0)
            return false;
        //without extra space
        int xx = x;
        int length = 0;
        while (x != 0) {
            x /= 10;
            length++;
        }
        int index = 0;
        int sum = 0;
        while (index < length / 2) {
            sum = sum * 10 + xx % 10;
            xx /= 10;
            index++;
        }
        if (length % 2 == 0 && xx == sum)
            return true;
        if (length % 2 == 1 && xx / 10 == sum)
            return true;
        return false;
    }
};

int main(){
    int number = 0;
    Solution solution;
    bool result = solution.isPalindrome(number);
    bool result_criterion = solution.isPalindrome_criterion(number);
    cout<<result<<endl;
    cout<<result_criterion<<endl;
    return 0;

}
