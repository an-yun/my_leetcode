#include "zuo/treenode.hpp"
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
class Solution
{
    TreeNode *buildBST(size_t n)
    {
        if (n)
        {
            list<TreeNode *> node_q;
            auto root = new TreeNode(0);
            node_q.push_back(root);
            while (--n)
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
            }
            return root;
        }
        else
            return nullptr;
    }
    void fillAscendingOrder(TreeNode *root, vector<int> &nums, size_t &index)
    {
        if(root)
        {
            fillAscendingOrder(root->left, nums, index);
            root->val = nums[index++];
            fillAscendingOrder(root->right, nums, index);
        }
    }

  public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        size_t n = nums.size();
        auto tree = buildBST(n);
        size_t index = 0;
        fillAscendingOrder(tree, nums, index);
        return tree;
    }
};

int main()
{
    Solution s;
    vector<int> nums{-10,-3,0,5,9};
    auto tree = s.sortedArrayToBST(nums);
    println(tree);
    free_tree(tree);
    return 0;
}
