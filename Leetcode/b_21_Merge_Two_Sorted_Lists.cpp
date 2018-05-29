//
// Created by Mr.Hu on 2018/5/29.
//
// leetcode 21 merge two sorted lists
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode result = ListNode(0);
        ListNode *current = &result;
        while (l1 && l2) {

            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        current->next = l1 ? l1 : l2;

        return result.next;
    }
};


int main() {
    ListNode one = ListNode(1);
    ListNode two = ListNode(2);
    ListNode three = ListNode(3);
    ListNode four = ListNode(4);
    ListNode five = ListNode(5);
    ListNode six = ListNode(6);
    // 指针用*，地址用&
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    five.next = &six;

    ListNode seven = ListNode(7);
    ListNode eight = ListNode(8);
    ListNode nine = ListNode(9);
    ListNode ten = ListNode(10);
    ListNode eleven = ListNode(11);
    ListNode twelve = ListNode(12);
    // 指针用*，地址用&
    seven.next = &eight;
    eight.next = &nine;
    nine.next = &ten;
    ten.next = &eleven;
    eleven.next = &twelve;

    Solution solution;
    ListNode *result = solution.mergeTwoLists(&one, &seven);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}