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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0),dummy2(0);
        auto h1 = &dummy1,h2= &dummy2; 
        while(head)
        {
            if(head->val < x)
            {
                h1->next = head;
                h1 = h1->next;
            }
            else
            {
                h2->next = head;
                h2 = h2->next;
            }
            head = head->next;
        }
        h1->next = dummy2.next;
        h2->next = nullptr;
        return dummy1.next;
    }
};


int main()
{
    Solution s;
    auto head = make_list({});
    println(s.partition(head, 3));
    return 0;
}

