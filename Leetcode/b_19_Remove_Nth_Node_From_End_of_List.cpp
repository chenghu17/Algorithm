//
// Created by Mr.Hu on 2019/3/28.
//
// leetcode 19 remove nth node from end of list
//
// 题目要求移除链表中倒数的第n个节点；
//
// 这里可以使用常用的快慢指针的方法，快指针先走n步，然后快慢指针一块走，当快指针到达最后一个节点时，
// 慢指针则在待删除的节点的前一个节点。值得注意的是，会出现删除第一个头节点的情况，所以这种情况需要单独考虑。
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // 快慢指针，慢指针等快指针走n-1步后开始
        ListNode *quick = head;
        ListNode *slow = head;
        // 快指针先走n步
        while (n) {
            quick = quick->next;
            n--;
        }
        // n为链表的长度，删除第一个节点
        if (quick == nullptr) {
            return head->next;
        }
        // n为中间或者最后节点
        while (quick->next != nullptr) {
            quick = quick->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
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
    c.next = &d;
    d.next = &e;
    Solution solution;
    ListNode *head = solution.removeNthFromEnd(&a, 3);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}