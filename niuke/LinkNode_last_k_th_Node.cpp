//
// Created by Mr.Hu on 2019/8/27.
//
//  牛客网 剑指offer 代码的鲁棒性
//  输入一个链表，输出该链表中倒数第k个结点。
//
//  思路：两个指针，分别为快和慢指针，快指针先走k步，慢指针再走
//  当快指针走到尾部时，慢指针正好是倒数第k个
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
        if (k <= 0 or pListHead == nullptr) {
            return nullptr;
        }

        ListNode *fastNode = pListHead;
        ListNode *lowNode = pListHead;
        while (--k && fastNode != nullptr) {
            fastNode = fastNode->next;
        }
        if (k != 0 or fastNode == nullptr) {
            return nullptr;
        }
        while (fastNode->next != nullptr) {
            fastNode = fastNode->next;
            lowNode = lowNode->next;
        }
        return lowNode;
    }
};

int main() {
    Solution solution;
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    a.next = &b;
    b.next = &c;
    ListNode *last_kth = solution.FindKthToTail(&a, 1);
    if (last_kth) {
        cout << last_kth->val << endl;
    } else {
        cout << "nullptr" << endl;
    }

    return 0;
}