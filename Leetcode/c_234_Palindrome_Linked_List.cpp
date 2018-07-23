//
// Created by Mr.Hu on 2018/7/23.
//
// leetcode 234 palindrome linked list
//


#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        ListNode *head_left = head;
        if (head == nullptr) {
            return true;
        }
        ListNode *head_right = head->next;
        int count = 0;
        while (head != nullptr) {
            ++count;
            head = head->next;
        }
        int middle = count / 2;
        head_left->next = nullptr;
        while (middle > 1 && head_right->next != nullptr) {
            ListNode *tmp_left = head_right;
            ListNode *tmp_right = head_right->next;
            head_right->next = head_left;
            head_left = tmp_left;
            head_right = tmp_right;
            --middle;
        }
        if (count % 2 != 0 && count != 1) {
            head_right = head_right->next;
        }
        bool isPalin = true;
        while (head_left != nullptr && head_right != nullptr) {
            if (head_left->val != head_right->val) {
                isPalin = false;
                break;
            }
            head_left = head_left->next;
            head_right = head_right->next;
        }
        return isPalin;
    }
};

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(3);
    ListNode f(2);
    ListNode g(1);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    Solution solution;
    bool isPalin = solution.isPalindrome(&a);
    cout << isPalin;
    return 0;
}