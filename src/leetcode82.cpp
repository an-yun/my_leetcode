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

int main()
{
    Solution s;
    auto head = make_list({1,1,5,5,2});
    println(s.deleteDuplicates(head));
    return 0;
}

