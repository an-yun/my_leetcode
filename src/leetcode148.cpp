#include "zuo/ioutils.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <list>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(! head || !head->next)
            return head;
        // use merge sort
        auto mid = head, tail = head, pre_mid = mid;
        while (tail && tail->next)
        {
            pre_mid = mid;
            mid = mid->next;
            tail = tail->next->next;
        }
        pre_mid->next = nullptr;
        // sort two sub list, swap node
        head = sortList(head);
        mid = sortList(mid);
        //merge
        ListNode dummy_head(-1);
        auto merge_position = &dummy_head;
        while (head && mid)
        {
            if(mid->val < head->val)
            {
                merge_position->next = mid;
                mid = mid->next;
            }
            else
            {
                merge_position->next = head;
                head = head->next;
            }
            merge_position = merge_position->next;
        }
        if(head)
            merge_position->next = head;
        else merge_position->next = mid;
        return dummy_head.next;
    }
};

ListNode *make_list(initializer_list<int> nums)
{
    //sort(nums.begin(), nums.end());
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
    print(head->val);
    head = head->next;
    while (head)
    {
        print("->");
        print(head->val);
        head = head->next;
    }
    println();
}

int main()
{
    Solution s;
    auto head = make_list({-1,5, 3, 4, 0});
    print_list(s.sortList(head));
    return 0;
}
