//
// Created by Mr.Hu on 2019/9/9.
//
// 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
//
// 解题方法比较简单，注意空链表的情况，已经确保最终输出的是合并后链表的头节点
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
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        ListNode *pHead = nullptr;
        ListNode *cur = nullptr;
        if (pHead1 == nullptr && pHead2 == nullptr) {
            return cur;
        }
        if (pHead1 == nullptr || pHead2 == nullptr) {
            return pHead1 != nullptr ? pHead1 : pHead2;
        }

        while (pHead1 != nullptr && pHead2 != nullptr) {
            if (pHead1->val < pHead2->val) {
                if (cur == nullptr) {
                    pHead = pHead1;
                    cur = pHead1;
                } else {
                    cur->next = pHead1;
                    cur = cur->next;
                }
                pHead1 = pHead1->next;
            } else {
                if (cur == nullptr) {
                    pHead = pHead2;
                    cur = pHead2;
                } else {
                    cur->next = pHead2;
                    cur = cur->next;
                }
                pHead2 = pHead2->next;
            }
        }
        if (pHead1 == nullptr) {
            cur->next = pHead2;
        } else {
            cur->next = pHead1;
        }
        return pHead;

    }
};

int main() {
    ListNode a1(1);
    ListNode b1(3);
    ListNode c1(5);
    ListNode d1(7);
    ListNode a2(2);
    ListNode b2(4);
    ListNode c2(6);
    ListNode d2(8);
    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;
    a2.next = &b2;
    b2.next = &c2;
    c2.next = &d2;
    Solution solution;
    ListNode *pHead = solution.Merge(&a1, &a2);
    while (pHead != nullptr) {
        cout << pHead->val << endl;
        pHead = pHead->next;
    }
    return 0;
}