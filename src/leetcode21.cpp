#include <iostream>
#include <vector>
#include "zuo/listnode.hpp"

using namespace std;


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode dump(0),*pre =&dump;
        while(l1 && l2)
        {
            if(l1->val <= l2 ->val)
            {
                pre->next = l1;
                pre=l1;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2;
                pre=l2;
                l2 = l2->next;
            }
        }
        if(l1) { pre->next = l1; }
        else { pre->next = l2; }
        return dump.next;

    }
};


ListNode* test_solution(initializer_list<int> array1,initializer_list<int> array2)
{
    auto l1 = make_list(array1), l2 = make_list(array2);
    Solution s;
    auto merge_list = s.mergeTwoLists(l1,l2);
    return merge_list;
}


int main(int argc, char const *argv[])
{
    auto list = test_solution({1, 2, 4}, {1, 3, 4});
    println(list);
    return 0;
}

