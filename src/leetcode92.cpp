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


int main()
{
    Solution s;
    auto head = make_list({1});
    println(s.reverseBetween(head, 1, 1));
    return 0;
}

