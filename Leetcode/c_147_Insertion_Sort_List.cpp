//
// Created by Mr.Hu on 2018/8/2.
//
// leetcode 147 Insertion sort List
//
// 题目要求对给定的链表采用插入排序
//
// 链表使用插入排序比较棘手的地方就是前后两个节点的地址都要知道，
// 所以我对这个题目进行解答的思想是：判断当前节点与第一个节点的大小关系，小于第一个节点，则current->next=first;
// first = current，否则判断节点与前后节点的关系，即current->val与tmp->val和tmp->next->val的大小关系，
// 如果存在其中，则current->next = tmp->next,tmp->next = current，
// 最后一种情况就是循环到最后一个节点，tmp->next == nullptr，有之前的两个判断条件，此时一定有current->val>tmp->val
// 整个题目的逻辑就是如此，需要两层while循环，第一层为待排序链表node，第二层为已经排序的链表node
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