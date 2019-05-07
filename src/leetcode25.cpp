#include <iostream>
#include <vector>
#include "zuo/listnode.hpp"

using namespace std;


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return  head;
        ListNode *start,*end, *pre = NULL;
        start = end = head;
        for(int i=1;i<k;i++) 
        {
            if(!end->next) return head;
            end =end->next;
        }
        head = end;
        while (true)
        {
            // conect pre segment
            if(pre) pre->next = end;
            pre = start;
            // reverse
            ListNode *next = start->next,*temp;
            start->next = NULL;
            while(start != end)
            {
                temp = next->next;
                next->next = start;
                start = next;
                next = temp;
            }
            //move to next segment
            if(next)
            {
                start = end = next;
                for(int i=1;i<k;i++) 
                {
                    if(!end->next) 
                    {
                        pre->next = start;
                        return head;
                    }
                    end =end->next;
                }
            }
            else return head;
            
        }
    }
};


ListNode* test_solution(initializer_list<int> array,int k)
{
    auto head = make_list(array);
    Solution s;
    auto reverse_list = s.reverseKGroup(head, k);
    return reverse_list;
}


int main(int argc, char const *argv[])
{
    auto list = test_solution({},1);
    println(list);
    return 0;
}

