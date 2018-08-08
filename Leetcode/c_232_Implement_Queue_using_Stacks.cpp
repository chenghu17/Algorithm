//
// Created by Mr.Hu on 2018/8/8.
//
// leetcode 232 implement queue using stacks
//
// 这个题目要求使用stack来实现queue的push、pop、peek、empty()方法
//
// 对于之前使用queue来实现mini_stack，用两个queue来存储内容。
// 在这里我也使用两个stack来存储数据，其实stack_one就是平时最常规的栈操作，栈顶元素即为刚加入的元素；
// stack_two用来表示队列的存储顺序，即栈顶元素为队头的元素。为了实现这两个栈的相互协作：
// 使用is_sequence这个bool变量来定义当前状态，true表示数据在stack_two中，且栈顶元素即为队头元素，
// 如果为false，则栈顶元素为队尾元素。
//
// 在执行push()操作时，即需要将数据压到队尾元素的后面，如果此时is_squence为false，则是stack_one
// 存储数据，所以直接push()即可保证数据的顺序；如果为false，则stack_two存储数据，此时想要保证数据的顺序，
// 则需要将stack_two中的数据依此压入stack_one中，然后将待push()的值push到stack_one中。
//
// 对于pop()和peek()操作类似，只是此时需要保证is_sequence为true，直接从stack_two中取元素
// empty()则直接返回两个stack的是否为空的状态即可。

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stack_one, stack_two;
    bool is_sequence = false;

    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        // stack_two中存储有序，即栈顶元素为队头元素，
        // stack_one中存储倒叙，即栈顶元素为队尾元素。
        if (is_sequence) {
            while (!stack_two.empty()) {
                stack_one.push(stack_two.top());
                stack_two.pop();
            }
        }
        is_sequence = false;
        stack_one.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!is_sequence) {
            while (!stack_one.empty()) {
                stack_two.push(stack_one.top());
                stack_one.pop();
            }
        }
        is_sequence = true;
        int result = stack_two.top();
        stack_two.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        if (!is_sequence) {
            while (!stack_one.empty()) {
                stack_two.push(stack_one.top());
                stack_one.pop();
            }
        }
        is_sequence = true;
        return stack_two.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return is_sequence ? stack_two.empty() : stack_one.empty();
    }
};

int main() {
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << obj->peek() << endl;
    obj->pop();
    cout << obj->peek() << endl;
    obj->pop();
    cout << obj->peek() << endl;
    return 0;
}