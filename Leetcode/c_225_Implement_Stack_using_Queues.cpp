//
// Created by Mr.Hu on 2018/7/19.
//
// 题目要求使用队列来实现栈的push、pop、top、isempty()。
// 对于队列queue，其中包含push、pop、front、isempty()操作，
// 由于queque满足FIFO特点，所以要想其像stack一样工作，则每次对queue进行push操作后，需要将push的值移动到队列的最前面，
// 这样当调用队列的front和pop时，才是最近进入的元素，从而表现出LIFO的效果。
// 而stack的top操作，在这里就是queue的front操作。
// 解这个方法的核心就是每次push值到queue的front位置，这就要求将queue中现有的element全部往后移动一位。
//

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> list;

    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        list.push(x);
        for (int i = 1; i < list.size(); ++i) {
            list.push(list.front());
            list.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = list.front();
        list.pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        return list.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return list.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

int main(){
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout<<obj->top()<<endl;
    cout<<obj->pop()<<endl;
    cout<<obj->empty()<<endl;
    delete obj;
    return 0;
}