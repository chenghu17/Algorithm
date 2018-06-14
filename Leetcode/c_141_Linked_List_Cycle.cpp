//
// Created by Mr.Hu on 2018/6/14.
//
// leetcode 141 linked list cycle
//
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
    bool hascyc(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};


int main() {
    // negtive
//    ListNode a = ListNode(1);
//    ListNode b = ListNode(2);
//    ListNode c = ListNode(3);
//    ListNode d = ListNode(2);
//    ListNode e = ListNode(3);
//    a.next = &b;
//    b.next = &c;
//    c.next = &d;
//    d.next = &e;
    //  positive
    ListNode a = ListNode(1);
    ListNode b = ListNode(2);
    ListNode c = ListNode(3);
    a.next = &b;
    b.next = &c;
    c.next = &b;
    Solution solution;
    bool result = solution.hascyc(&a);
    cout << result << endl;
    return 0;
}