#include "zuo/listnode.hpp"
#include <algorithm>

using namespace std;


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
        auto pre = head,cur = head->next;
        while( cur )
        {
            if(cur->val == pre->val) pre->next = cur->next;
            else pre =pre->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};

int main()
{
    Solution s;
    auto head = make_list({1,1,2});
    println(s.deleteDuplicates(head));
    return 0;
}

