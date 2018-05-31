//
// Created by Mr.Hu on 2018/5/31.
//
// leetcode 206 reverse linked list
//
// 题目要求对给定的链表进行反转。
//
// 该题解法有递归和迭代两种方式：这里先采用递归的方法
// 要想将链表进行反转，则需要从最后一个位置开始。因为如果从开头开始，则会丢失next的地址信息。
// 最后一位的next要等于其上一位，即A->next->next = A;
// 操作完之后，上一位A->next = NULL，用于存储其A的上一位，还是上面这个步骤。
// 所以我们递归的调用reevesList方法，每次传递head->next，直到转递到倒数第二位停止：
// 所以有判断条件nullptr == head || nullptr == head->next，前者是排除掉最后一位的next，后者是排除掉最后一位；
// 因为想要reverse，必须要最后一位和倒数第二位，而单向链表只能向前，所以只有直到前一位地址，才能当前位与前一位进行反转。
//
// 由于对递归不熟悉，这个题目通过查阅答案后才完成。后续对递归、回溯这样的方法要进行深入学习。
//

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};

int main() {
    ListNode one = ListNode(1);
    ListNode two = ListNode(2);
    ListNode three = ListNode(3);
    ListNode four = ListNode(4);
    one.next = &two;
    two.next = &three;
    three.next = &four;
    Solution solution;
    ListNode *result = solution.reverseList(&one);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
