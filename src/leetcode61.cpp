#include "zuo/listnode.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;


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

int main()
{
    Solution s;
    auto head = make_list({0, 1, 2});
    println(s.rotateRight(head, 4));
    return 0;
}
