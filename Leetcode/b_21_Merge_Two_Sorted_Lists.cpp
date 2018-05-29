//
// Created by Mr.Hu on 2018/5/29.
//
// leetcode 21 merge two sorted lists
//
// 题目要求对排序链表进行合并
//
// 刚开始的想法是用一个新的链表来存储两个链表中的所有节点，哪个链表当前节点的值最小则加入进来；
// 但是在执行的过程中遇到一个问题，就是新链表中当前current节点在扩展下一个节点时，会丢弃上一个节点...具体原因不明
// 由于自己对链表擦操作本来就不熟悉，所以去找了别人的方法：
// 原来可以先自己定义一个头节点result，并将地址传递给current然后将其next指针指向来l1和l2中val值较小的节点，
// result用来最后返回链表地址，而current用来表示新加入的节点位置
// 循环完之后，判断l1和l2是否还有剩余的子链表，有的话则将current->next直接执行了或者l2。
// 由于result的头节点是我们自己随意定义的一个，真正开始的位置是头节点的下一个，所以我们返回result->next指针。
//
// 我刚开始的那种想法应该也是可以实现的，只是存在一处bug。但是我把代码给删除了...做其他linked list时再思考。
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode result = ListNode(0);
        ListNode *current = &result;
        while (l1 && l2) {

            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        current->next = l1 ? l1 : l2;

        return result.next;
    }
};


int main() {
    ListNode one = ListNode(1);
    ListNode two = ListNode(2);
    ListNode three = ListNode(3);
    ListNode four = ListNode(4);
    ListNode five = ListNode(5);
    ListNode six = ListNode(6);
    // 指针用*，地址用&
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    five.next = &six;

    ListNode seven = ListNode(7);
    ListNode eight = ListNode(8);
    ListNode nine = ListNode(9);
    ListNode ten = ListNode(10);
    ListNode eleven = ListNode(11);
    ListNode twelve = ListNode(12);
    // 指针用*，地址用&
    seven.next = &eight;
    eight.next = &nine;
    nine.next = &ten;
    ten.next = &eleven;
    eleven.next = &twelve;

    Solution solution;
    ListNode *result = solution.mergeTwoLists(&one, &seven);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}