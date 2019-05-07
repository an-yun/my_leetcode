#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include <vector>
#include "zuo/ioutils.hpp"

/**
 * Definition for singly-linked list.
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode *make_list(std::initializer_list<int> nums)
{
    ListNode *dummy_head = new ListNode(0), *node = dummy_head;
    for (auto num : nums)
    {
        node->next = new ListNode(num);
        node = node->next;
    }
    node = dummy_head->next;
    delete dummy_head;
    return node;
}

void print_list(ListNode *head)
{
    if(head)
    {
        print(head->val);
        head = head->next;
        while (head)
        {
            print("->");
            print(head->val);
            head = head->next;
        }
    }
}
// 打印ListNode类型
inline void print(ListNode *node)
{
    print_list(node);
}
inline void println(ListNode *node)
{
    print_list(node);
    println();
}


#endif