#include "zuo/ioutils.hpp"
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        auto pre = &dummy;
        int i = 1;
        for (; i < m; ++i)
            pre = pre->next;
        auto r_head = pre->next, node = r_head->next,r_end = r_head;
        for (; i < n; ++i)
        {
            auto temp = node->next;
            node->next = r_head;
            r_head = node;
            node = temp;
        }
        pre->next = r_head;
        r_end->next = node;
        return dummy.next;
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
    auto head = make_list({1});
    print_list(s.reverseBetween(head, 1, 1));
    return 0;
}

