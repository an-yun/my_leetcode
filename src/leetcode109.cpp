#include "zuo/treenode.hpp"
#include "zuo/listnode.hpp"
#include <algorithm>
#include <list>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    TreeNode *buildBST(ListNode* head)
    {
        if (head)
        {
            list<TreeNode *> node_q;
            auto root = new TreeNode(0);
            node_q.push_back(root);
            while (head->next)
            {
                auto node = node_q.front();
                auto new_node = new TreeNode(0);
                node_q.push_back(new_node);
                if (node->left)
                {
                    node->right = new_node;
                    node_q.pop_front();
                }
                else
                    node->left = new_node;
                head = head->next;
            }
            return root;
        }
        else
            return nullptr;
    }
    void fillAscendingOrder(TreeNode *root, ListNode* &head)
    {
        if(root)
        {
            fillAscendingOrder(root->left, head);
            root->val = head->val;
            head = head->next;
            fillAscendingOrder(root->right, head);
        }
    }

  public:
    TreeNode *sortedListToBST(ListNode* head)
    {
        auto tree = buildBST(head);
        fillAscendingOrder(tree, head);
        return tree;
    }
};

int main()
{
    Solution s;
    auto head = make_list({-10, -3, 0, 5, 9});
    auto tree = s.sortedListToBST(head);
    println(tree);
    free_tree(tree);
    free_list(head);
    return 0;
}
