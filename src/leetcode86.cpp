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
    auto head = make_list({});
    print_list(s.partition(head, 3));
    return 0;
}

