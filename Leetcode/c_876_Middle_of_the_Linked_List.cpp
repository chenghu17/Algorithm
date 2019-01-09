//
// Created by Mr.Hu on 2019/1/9.
//
// leetcode 876 middle of the linked list
//
// 题目给出一个长度为[1,100]区间的链表，要求找出该链表的中间节点。
//
// 先遍历链表，得到链表的实际长度，得到中间节点的index，然后再遍历找到中间节点。
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        int node_count = 1;
        ListNode *cur = head;
        while (cur->next) {
            cur = cur->next;
            node_count++;
        }
        int middle = node_count / 2;
        cur = head;
        while (middle - 1 >= 0) {
            cur = cur->next;
            middle--;
        }
        return cur;
    }
};

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    Solution solution;
    ListNode *middle = solution.middleNode(&a);
    cout << middle->val << endl;
    return 0;
}