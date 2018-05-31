//
// Created by Mr.Hu on 2018/5/31.
//
// leetcode 206 reverse linked list
//


#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};

int main() {
    ListNode one = ListNode(1);
    ListNode two = ListNode(2);
    ListNode three = ListNode(3);
    ListNode four = ListNode(4);
    one.next = &two;
    two.next = &three;
    three.next = &four;
    Solution solution;
    ListNode *result = solution.reverseList(&one);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
