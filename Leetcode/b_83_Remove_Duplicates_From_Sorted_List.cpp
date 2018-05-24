//
// Created by Mr.Hu on 2018/5/24.
//
// leetcode 83 remove duplicated from sorted list
//
//
//
//

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    // 构造函数
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *current = head;
        ListNode *next = current->next;
        while (next != nullptr) {
            if (next->val == current->val) {
                current->next = next->next;
            } else {
                current = next;
            }
            next = current->next;
        }
        return head;
    }
};

int main() {
    ListNode one = ListNode(1);
    ListNode two = ListNode(1);
    ListNode three = ListNode(1);
    ListNode four = ListNode(2);
    ListNode five = ListNode(3);
    ListNode six = ListNode(4);
    // 指针用*，地址用&
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    five.next = &six;
    Solution solution;
    ListNode *result = solution.deleteDuplicates(&one);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}

