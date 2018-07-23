//
// Created by Mr.Hu on 2018/7/23.
//
// 知识点：将一个单链表反向翻转
//
// 核心：用两个临时链表指针保存当前left和right指针
//


#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode *reverse_linked_list(ListNode *head) {
    ListNode *head_left = head;
    ListNode *head_right = head->next;
    head_left->next = nullptr;
    while (head_right->next != nullptr) {
        ListNode *tmp_left = head_right;
        ListNode *tmp_right = head_right->next;
        head_right->next = head_left;
        head_left = tmp_left;
        head_right = tmp_right;
    }
    head_right->next = head_left;
    return head_right;
}

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
    ListNode *head = &a;
    while (head->next != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << head->val << endl;

    head = reverse_linked_list(&a);

    while (head->next != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << head->val;

    return 0;
}