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
class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        ListNode dummy(0);
        dummy.next = head;
        auto pre = &dummy,cur = head->next;
        bool is_same =false;
        while( cur )
        {
            if(cur->val == pre->next->val)
                is_same = true;
            else
            {
                if(is_same) 
                {
                    pre->next = cur;
                    is_same = false;
                }
                else
                    pre = pre->next;
                
            }
            cur = cur->next;
        }
        if(is_same) pre->next = nullptr;
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
    auto head = make_list({1,1,5,5,2});
    print_list(s.deleteDuplicates(head));
    return 0;
}

