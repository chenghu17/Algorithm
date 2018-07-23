//
// Created by Mr.Hu on 2018/7/23.
//
// leetcode 234 palindrome linked list
//
// 题目要求判断一个单链表是否为回文链，即从满足具有回文特性
//
// 这个题目还要求时间复杂度为O(n)，空间复杂度为O(1)
// 题目的主要思想是如何解决单链表从后向前遍历，想要解决这个问题，就需要将单链表进行翻转(reverse)
// 但是如果将单链表完全翻转，也无法判断该链表是否为回文串，毕竟空间复杂度要求为O(1)
// 所以想到要判断回文串，只需要找到串的中间位置，左边串进行从右往左遍历，右边串进行从左往右遍历
// 而现在的目标就是将前半部分进行翻转，翻转后分别得到前半部分的head_left和右半部分的head_right，
// （此处要判断单链表节点的个数，奇数和偶数决定了head_right和head_left的位置）
// 于是我们在code中将单链表进行翻转，维护两个节点指针来保存当前的head_left和head_right，判断条件是
// head->right!=nullptr且middle的值减小到1，最后head_left和head_right同步遍历链表即可得到最终的结果。
//
// 这个题目将链表翻转以及回文串的特点相结合，虽然level属于easy，但是很具备代表性，且需要清晰的知道各种边界值
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