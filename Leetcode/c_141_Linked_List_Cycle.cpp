//
// Created by Mr.Hu on 2018/6/14.
//
// leetcode 141 linked list cycle
//
// 题目要求判断链表中是否存在环。
//
// 由于对于链表的不熟悉，所以刚开始我认为的环就是1-->2-->3-->2-->1，类似这种在数字上相同的相等的情况，有点像回文数；
// 其实所谓的存在环，是存在一个node，其next指向的是其之前的一个node，这样就存在环！
// 要想判断是否存在这样的情况，我去参考了一下别人的做法，决定蚕蛹two points的方法来解决这个问题，而这种方法的思想
// 就相当于在操场上跑步的追击问题，一个point跑的快，一个point跑的慢，只要时间够长，他们两总会相遇。
// 所以我们在这里使用两个point，一个slower，每次向前走一步，一个faster，每次向前走两步，如果slow == fast,
// 说明两个指针回到了一个node，即肯定存在环，如果知道fast走到链表的end位置，还还没有出现slow == fast的情况，
// 则说明不存在环，return false.
//
// 接下来两三天专门练习linked list方面的题目，在学习中理解pointer的魅力
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