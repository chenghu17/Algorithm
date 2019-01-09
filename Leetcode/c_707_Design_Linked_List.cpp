//
// Created by Mr.Hu on 2019/1/9.
//
// leetcode 707 design linked list
//
// 题目要求实现链表。其中包括get(index)、三种insert、一种delete方法。
//
// 首先用struct来定义链表中的每个节点。
// 对于三种方法，要认真的去思考链表的属性。
// 主要是：头尾指针刚开始为nullptr，当插入第一个节点后，头尾指针指向同一个节点。
// 在插入头或者尾时，就需要考虑当前链表是否为空，以及当前头尾指针是否指向同一个节点。
// 当删除节点时，需要考虑当前链表是否只存在一个节点；删除的是否为第一个节点；删除的是否为尾节点；删除的是中间节点。
//
// 刚开始程序出现了两个bug：第一个是我在if判断是否相等时，写成了赋值...；第二个是在添加节点的越界操作：index>length处，加了等号...
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {};
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    ListNode *head;
    ListNode *tail;
    int length;

    MyLinkedList() {
        length = 0;
        head = nullptr;
        tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (length <= index || index < 0) {
            return -1;
        } else {
            // search
            ListNode *cur_node = head;
            while (index > 0) {
                cur_node = cur_node->next;
                index--;
            }
            return cur_node->val;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (!head && !tail) {
            head = new ListNode(val);
            tail = head;
        } else if (head == tail) {
            ListNode *node = new ListNode(val);
            head = node;
            head->next = tail;
        } else {
            ListNode *node = new ListNode(val);
            node->next = head;
            head = node;
        }
        length++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (!head && !tail) {
            tail = new ListNode(val);
            head = tail;
        } else if (head == tail) {
            ListNode *node = new ListNode(val);
            tail = node;
            head->next = tail;
        } else {
            ListNode *node = new ListNode(val);
            tail->next = node;
            tail = node;
        }
        length++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > length) {
            return;
        } else if (index == 0) {
            addAtHead(val);
        } else if (index == length) {
            addAtTail(val);
        } else {
            // search
            ListNode *cur_node = head;
            ListNode *node = new ListNode(val);
            while (index - 1 > 0) {
                cur_node = cur_node->next;
                index--;
            }
            node->next = cur_node->next;
            cur_node->next = node;
            length++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) {
            return;
        }
            // delete
        else if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else if (index == 0) {
            head = head->next;
        } else if (index == length - 1) {
            ListNode *pre_node = head;
            while (index - 1 > 0) {
                pre_node = pre_node->next;
                index--;
            }
            pre_node->next = nullptr;
            tail = pre_node;
        } else {
            // search
            ListNode *pre_node = head;
            while (index - 1 > 0) {
                pre_node = pre_node->next;
                index--;
            }
            pre_node->next = pre_node->next->next;

        }
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
int main() {
    MyLinkedList *obj = new MyLinkedList();
    int param_1 = obj->get(0);
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    int param_2 = obj->get(1);
    obj->deleteAtIndex(1);
    int param_3 = obj->get(1);
    cout << "expect: param_1=-1; param_2=2; param_3=3" << endl;
    cout << " fact : param_1=" << param_1 << "; param_2=" << param_2 << "; param_3=" << param_3 << endl;
    return 0;


}
