//
// Created by Mr.Hu on 2018/6/18.
//
// leetcode 160 intersction of two linked lists
//


#include <iostream>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {};
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode *, int> tmp;
        int count = 1;
        while (headA != nullptr) {
            tmp[headA] = count;
            ++count;
            headA = headA->next;
        }
        while (headB != nullptr) {
            if (tmp[headB] != 0) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    e.next = &d;
    d.next = &c;
    Solution solution;
    ListNode *intersection = solution.getIntersectionNode(&a, &e);
    cout << intersection << ":" << intersection->val;
    return 0;
}