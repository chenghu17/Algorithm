//
// Created by Mr.Hu on 2018/6/18.
//
// leetcode 160 intersction of two linked lists
//
// 题目要求对于两个单链表，找出其交叉node并返回，如果不存在交叉节点，则返回nullptr
//
// 第一中想法就是蛮力法：将a中的每一个节点和b中的每一个节点进行对比，存在相同则返回相应的listnode，不存在则返回nullptr
// 这种做法的复杂度为O(m*n)，会导致time limit exceeded
//
// 然后想到第二种方法，hash table的方式，将链表a中的所有节点存储在map中，然后b中的所有节点与map中内容对比。
// 这种做法我在刚开始想到的时候给排除了，因为我只想到用map<int,int>来存储a中所有node，key为index，value为val，
// 但是这种做法一是要求b中只有交叉node的val值与a相等，其他节点不存在这种情况；另外就是b中的node的val值要与map中的value进行对比，是一个很复杂的过程；
// 所以我就去看了官方的solution，也是提出可以使用hash set的方式，原来hash set的key可以存储指针...
// 因此我就采用这种方式，定义map<ListNode* , int> tmp来存储a中的所有节点，value值定义为1，再对b进行遍历，判断b中node是否为map中的key值，
// 即tmp[listnode]!=0即可，该方法的时间复杂度为O(m+n)，空间复杂度为O(m)或O(n)。
// 但是这种方式的runtime值击败来百分之十二左右的accepted solution。
//
// 当时也想了另外一种想法，也是single linked list中经常遇到的一种方法 two pointers。
// 这种方法也是官方给出的第三种方法：同时对链表A和B遍历，步长都为1，当A到达end时，重定向到headB继续遍历，
// 同理，当B达到end时，重定向到headA继续遍历，最后即为intersection node，但是这种方法我还没有理解...
// 等理解了再写出来
//

#include <iostream>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {};
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode *, int> tmp;
        while (headA != nullptr) {
            tmp[headA] = 1;
            headA = headA->next;
        }
        while (headB != nullptr) {
            if (tmp[headB] != 0) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    e.next = &d;
    d.next = &c;
    Solution solution;
    ListNode *intersection = solution.getIntersectionNode(&a, &e);
    cout << intersection << ":" << intersection->val;
    return 0;
}