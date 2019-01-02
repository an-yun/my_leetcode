#include <iostream>
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
ListNode* creat_list(vector<int> array)
{
    unsigned size = array.size();
    ListNode *head=NULL, *current;
    if(size != 0){
        head = new ListNode(array[0]);
        current = head;
        
        for (unsigned i = 1; i < size; i++)
        {
            current->next = new ListNode(array[i]);
            current = current->next;
        }
    }
    return head;
}

ListNode* test_solution(vector<int> array,int k)
{
    auto head = creat_list(array);
    Solution s;
    auto reverse_list = s.reverseKGroup(head, k);
    return reverse_list;
}

void pirnt_list(ListNode *head)
{
    while (head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    auto list = test_solution({},1);
    pirnt_list(list);
    return 0;
}

