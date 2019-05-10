#include "zuo/treenode.hpp"
#include <vector>

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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        list<TreeNode *> node_stack;
        while(root)
        {
            node_stack.push_back(root);
            root = root->left;
        }
        while(!node_stack.empty())
        {
            auto node = node_stack.back();
            node_stack.pop_back();
            result.push_back(node->val);
            node = node->right;
            while(node)
            {
                node_stack.push_back(node);
                node = node->left;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    auto tree = make_tree({1, null, 2, 3});
    println(s.inorderTraversal(tree));
    return 0;
}