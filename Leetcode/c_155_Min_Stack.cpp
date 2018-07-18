//
// Created by Mr.Hu on 2018/7/18.
//
// 题目要求设计一个栈，支持栈的基本操作，push、pop、top，并且实现getmin()方法，能够在O(1)复杂度上返回。
//
// 刚开始以为要用vector或者链表来进行底层实现，进行尝试之后，发现getmin()方法有问题，而且自己写的方法在
// 栈为空时返回报错int型结果报错，所以去查了一下别人的方法。
// 原来是通过STL中已有的stack工具库上层进行实现，为了能够实现getmin()在常数时间复杂度上返回，
// 这里定义了两个stack a,b，一个用来存储当前stack中的值，一个用来存储当前stack中最小的值，且两个stack的位数保持相同。
// 这个设计是相当妙的，因为在进行出栈操作时，对a，b进行pop操作，最后在getmin()方法中返回b.top()依旧是当前栈中最小值。
// 这依赖于push中的实现，在对b进行push时，如果当前b为空或者当前push的值x小于当前b.top()，则直接b.push(x)，
// 否则，将b当前的top重新push一次，即b.push(b.top())，这样在进行pop操作后，就算b.pop()，当前b.top()仍然是栈a中最小值。
// 这个设计可以说很妙，而且很有意思。值得学习。
//


#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> a, b;

    MinStack()= default;

    void push(int x) {
        a.push(x);
        if (b.empty() || x < b.top()) {
            b.push(x);
        } else {
            b.push(b.top());
        }
    }

    void pop() {
        a.pop();
        b.pop();
    }

    int top() {
        return a.top();
    }

    int getMin() {
        return b.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout << obj.getMin() << endl;
    obj.pop();
    cout << obj.top() << endl;
    cout << obj.getMin();
    return 0;


}