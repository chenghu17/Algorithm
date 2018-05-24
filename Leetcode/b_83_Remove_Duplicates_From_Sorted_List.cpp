//
// Created by Mr.Hu on 2018/5/24.
//
// leetcode 83 remove duplicated from sorted list
//
// 题目要求对给定有序链表，移除重复数据；
//
// 题目思想比较简单，就是对链表当前节点的value与下一个节点的value值进行比较，
// 如果相等，则将当前节点的next指针指向下一个节点的next节点，即删除来下一个节点；
// 如果不相等，则当前指针更新为下一个指针，下一个指针则更新为下下一个指针；
// 每次判断下一个指针是否为NULL(nullptr)，
// 如果为false，则重复上面的步骤。
// 如果为true，则说明链表以及遍历完，结束循环，返回链表头指针；
//
// 这个题目的想法比较简单，主要考察对链表节点的操作，由于对linked_list生疏，
// 导致coding时还是犯了不少错误，通过这类题目的训练可以加固对指针操作的熟悉度。
//
// 以下code的执行效率能够超过99.3%的cpp结果
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

//python代码再进行一次，已经通过leetcode测试
//# Definition for singly-linked list.
//# class ListNode:
//#     def __init__(self, x):
//#         self.val = x
//#         self.next = None
//
//class Solution:
//        def deleteDuplicates(self, head):
//"""
//:type head: ListNode
//        :rtype: ListNode
//"""
//if head == None:
//return head
//        current = head
//next = current.next
//while next != None:
//if current.val == next.val:
//        current.next = next.next
//else:
//current = next
//next = current.next
//return head


