//
// Created by Mr.Hu on 2019/2/21.
//
// leetcode 2 add two numbers
//
// 题目给定两个非空链表，分别表示表示两个整数，且以从个位到高位的顺序构建链表，要求两个数字的和，同样使用链表的形式输出。
//
// 题目已经大大简化了我们的工作，即不用翻转链表，我们只需要对应位置相加即可。
// l1和l2都从个位开始，对位进行加法，并保存进位状态，每次创建一个节点，当作last节点的next，并更新last位当前节点。
// 直到l1或者l2遍历完，则可能存在1、有一个链表还没加完；2、都加完但是进位状态中还有数字存在。
// 首先我们要对没有加完的链表继续累加，此时也要考虑当前进位carry的值。
// 最后链表加完之后，判断进位状态是否位1，是则需要创建一个节点，当作last的next，最后输出head节点即可。
//
// 题目本身不难，主要考察链表遍历，且对加法进位状态不能忽略。
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        int carry = 0;
        bool isfirst = true;
        ListNode *head;
        ListNode *last;
        int tmp;
        while (l1 != nullptr && l2 != nullptr) {
            tmp = l1->val + l2->val + carry;
            if (tmp > 9) {
                carry = 1;
            } else {
                carry = 0;
            }
            if (isfirst) {
                head = new ListNode(tmp % 10);
                last = head;
                isfirst = false;
            } else {
                last->next = new ListNode(tmp % 10);
                last = last->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 || l2) {
            ListNode *cur = l1 != nullptr ? l1 : l2;
            while (cur) {
                tmp = cur->val + carry;
                if (tmp > 9) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                last->next = new ListNode(tmp % 10);
                last = last->next;
                cur = cur->next;
            }
        }
        if (carry != 0) {
            last->next = new ListNode(carry);
        }

        return head;

    }
};