//
// Created by Mr.Hu on 2019/9/9.
//
// 输入一个链表，反转链表后，输出新链表的表头。
//
// 解答这题要注意判断链表的状态，是否为空链表
// 想要反转链表，即将某一个节点的next指针从指向其后面的节点，改为指向其前面的节点；
// 所以显然我们需要去记录当前节点（cur），前一个节点（pre），后一个节点（post）
//
// 值得主要的是：在获取node->next时，node一定不能为nullptr，否则回报空指针异常，这个应该是一个容易犯错的地方
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
    ListNode *ReverseList(ListNode *pHead) {
        if (pHead == nullptr) {
            return pHead;
        }
        ListNode *pre = nullptr;
        ListNode *cur = pHead;
        ListNode *post = pHead->next;
        while (cur != nullptr) {
            cur->next = pre;
            pre = cur;
            cur = post;
            if (cur == nullptr) {
                break;
            }
            post = post->next; // post为null，则post->next报空指针异常
        }
        return pre;
    }
};

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    Solution solution;
    ListNode *pHead = solution.ReverseList(&a);
    while (pHead != nullptr) {
        cout << pHead->val << endl;
        pHead = pHead->next;
    }
    return 0;
}