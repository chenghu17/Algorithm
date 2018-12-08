//
// Created by Mr.Hu on 2018/12/8.
//
//
//
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        stack<int> cur_stack;
        vector<int> result;
        int asteroids_number = asteroids.size();
        for (int i = 0; i < asteroids_number; ++i) {
            if (asteroids[i] < 0 & cur_stack.empty()) {
                result.push_back(asteroids[i]);
            } else if (asteroids[i] < 0 & !cur_stack.empty()) {
                bool flag = true;
                while (!cur_stack.empty()) {
                    int top = cur_stack.top();
                    if (top > -asteroids[i]) {
                        flag = false;
                        break;
                    } else if (top == -asteroids[i]) {
                        cur_stack.pop();
                        flag = false;
                        break;
                    } else {
                        cur_stack.pop();
                    }
                }
                if (flag) {
                    result.push_back(asteroids[i]);
                }
            } else {
                cur_stack.push(asteroids[i]);
            }
        }
        // 这里应该注意最终结果的顺序
        vector<int> tmp;
        while (!cur_stack.empty()) {
            tmp.push_back(cur_stack.top());
            cur_stack.pop();
        }
        for (int i = tmp.size() - 1; i >= 0; --i) {
            result.push_back(tmp[i]);
        }
        return result;
    }
};

int main() {
    vector<int> asteroids;
    asteroids.push_back(-2);
    asteroids.push_back(-2);
    asteroids.push_back(1);
    asteroids.push_back(-2);
    Solution solution;
    vector<int> result = solution.asteroidCollision(asteroids);
    for (auto it:result) {
        cout << it << " ";
    }
    return 0;
}