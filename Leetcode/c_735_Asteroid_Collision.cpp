//
// Created by Mr.Hu on 2018/12/8.
//
// leetcode 735 asteroids collision
//
// 题目给定一个行星运行场景：现有一个数组表示行星列表，数组中的每个值表示行星的体积，该值的符号为行星运行方向，
// 正数则表示向右运行，负数表示向左运行，所有行星以相同的速度运行，相同方向的行星永远不会相碰，
// 不同的行星一定会进行碰撞，在碰撞的过程中，谁的体积大，则谁保留（假设碰撞只会导致体积较小的行星消失，大体积的行星无任何损伤）
// 要求最终所有碰撞发生以后，保留下来的行星列表
//
// 这个题目算是一道理解题，要求我们能够迅速理解该场景并作出反应。
// 从题目可以发现，一个向左运行的行星，最先只会与其左边最近的反方向行星发生碰撞，碰撞胜利继续向左发生碰撞，如果左边没有，则该行星会最终保留。
// 所以现在我们以向左运行的行星为参考，向右运行的行星因为要满足上述要求，所以我们用栈结果来存储，即每次拿到与当前向左运行行星最近的逆向行星进行比较。
// 比较的过程就不重复了，代码for循环中已经给出。
//
// 还有一点需要注意的是，如果循环结束，stack中还存在元素，即存在一些都向右的行星，此时我们需要将这些行星加入到最终的结果列表中，而直接出栈加入，
// 会导致行星列表发生变化，因为越靠前的行星现在的位置在栈底，所以我们需要将栈底元素加入到前面，即扭转一下。
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