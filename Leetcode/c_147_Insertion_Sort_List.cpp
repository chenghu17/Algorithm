//
// Created by Mr.Hu on 2018/8/2.
//
// leetcode 147 Insertion sort List
//
//
//
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *start = head;
        if (head == nullptr || head->next == nullptr) {
            return start;
        }
        ListNode *current = start->next;
        start->next = nullptr;
        ListNode *current_next;
        ListNode *tmp;
        while (current != nullptr) {
            tmp = start;
            current_next = current->next;
            current->next = nullptr;
            // insert operation
            while (tmp != nullptr) {
                if (tmp == start) {
                    if (current->val < tmp->val) {
                        current->next = tmp;
                        start = current;
                        break;
                    }
                }
                if (tmp->next == nullptr) {
                    tmp->next = current;
                    break;
                } else if (current->val >= tmp->val && current->val <= tmp->next->val) {
                    current->next = tmp->next;
                    tmp->next = current;
                    break;
                } else {
                    tmp = tmp->next;
                }
            }
            // update
            current = current_next;
        }
        return start;
    }
};

int main() {
    ListNode a(4);
    ListNode b(2);
    ListNode c(1);
    ListNode d(3);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    Solution solution;
    ListNode *result = solution.insertionSortList(&a);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}