//
// Created by Mr.Hu on 2018/6/14.
//
// 题目要求将给定的节点从单链表中删除
//
// 当当前node的val和next都用node->next的val和next来赋值
// 然后使用删除原node，这里值得注意的是，在delete时，不能delete但前node的next，
// 因为经过上一步操作，node->next已经是其原来的next->next，所以我们在刚开始使用auto next来保存这个位置
// 最后直接delete这个ListNode next单独的节点就行。
//
// 这种手动delete，即清理内存的方式是一种很好的习惯。
//

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};

class Solution {
public:
    void deleteNode(ListNode *node) {
        auto next = node->next;
        node->val = next->val;
        node->next = next->next;
        // *node = *next;
        delete next;
    }
};

int main() {
    ListNode a(4);
    ListNode b(3);
    ListNode c(2);
    ListNode d(1);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    cout<<a.next->val<<endl;
    Solution solution;
    solution.deleteNode(&b);
    cout<<a.next->val<<endl;
    return 0;
}
