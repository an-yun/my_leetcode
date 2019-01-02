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

ListNode* test_solution(vector<int> array1,vector<int> array2)
{
    auto l1 = creat_list(array1), l2 = creat_list(array2);
    Solution s;
    auto merge_list = s.mergeTwoLists(l1,l2);
    return merge_list;
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
    auto list = test_solution({1, 2, 4}, {1, 3, 4});
    pirnt_list(list);
    return 0;
}

