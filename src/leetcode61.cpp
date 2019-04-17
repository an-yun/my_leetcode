#include "zuo/ioutils.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        auto tail = head->next;
        int lengh = 2;
        while (tail->next)
        {
            tail = tail->next;
            lengh++;
        }
        tail->next = head;
        int begin_position = lengh - k % lengh;
        auto rotate_begin = head;
        for (int i = 1; i < begin_position;i++)
            rotate_begin = rotate_begin->next;
        head = rotate_begin->next;
        rotate_begin->next = nullptr;
        return head;
    }
};

ListNode *make_list(initializer_list<int> nums)
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
    println();
}

int main()
{
    Solution s;
    auto head = make_list({0, 1, 2});
    print_list(s.rotateRight(head, 4));
    return 0;
}
