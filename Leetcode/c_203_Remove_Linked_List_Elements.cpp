//
// Created by Mr.Hu on 2018/6/14.
//
// leetcode 203 remove linked list elements
//
// 题目要求在给定的链表中删除对应val值的node
//
// 这个题目其实是在单链表中删除某个node的扩展，即删除满足条件的node。
// 最开始使用一个ListNode* first指针来存储head的地址，然后每次判断当前head的next是否为空，
// 不为空，则将head->next->val的值与给定的值比较，相等则删除next节点，即head->next = head->next->next;
// 接着继续循环，因为当前head->next是一个新的node，所以重新判断；
// 若不相等，则head = head->next，即当前节点向前移动一位，当前节点的val一定不等于val，所以继续判断next节点的val。
// 最后对first进行判断，也就是对链表的头节点进行判断，因为前面的循环是从第二个节点开始判断的，而最后要求返回首指针，
// 所以将首指针的情况最后判断，如果刚开始就判断，如果相等，那么首指针就要移动到下一位，而下一位又要做这样的判断，是一个相当繁琐的过程。
// 因此将首指针的情况放在最后，先将其他指针该删除的删除，该保留的保留。如果first->val == val，则return first->next;
// 否则，return first。
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr) {
            return head;
        }
        ListNode *first = head;
        while (head->next != nullptr) {
            if (head->next->val == val) {
                auto next_node = head->next;
                head->next = next_node->next;
//                delete next_node;
                next_node = nullptr;
            } else {
                head = head->next;
            }
        }
        if (first->val == val) {
            return first->next;
        }
        return first;
    }
};

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(3);
    ListNode f(2);
    ListNode g(6);
    ListNode h(7);
    ListNode i(2);
    ListNode j(8);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &h;
    h.next = &i;
    i.next = &j;
    Solution solution;
    ListNode *result = solution.removeElements(&a, 3);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}