#include "zuo/treenode.hpp"
#include <algorithm>
#include <list>
#include <utility>

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
    TreeNode *pre;
    void preorder(TreeNode *root)
    {
        if(root)
        {
            if(pre)
                pre->right = root;
            pre = root;
            auto l = pre->left, r = pre->right;
            pre->left = nullptr;
            preorder(l);
            preorder(r);
        }
    }
    pair<TreeNode *, TreeNode *> flatten_subtree(TreeNode *root)
    {
        if(root)
        {
            TreeNode *head = root, *tail,*temp = root->right;
            if (root->left)
            {
                auto l = flatten_subtree(root->left);
                root->left = nullptr;
                root->right = l.first;
                tail = l.second;
            }
            else
                tail = root;
            if (temp)
            {
                auto r = flatten_subtree(temp);
                tail->right = r.first;
                tail = r.second;
            }
            return {head, tail};
        }
        else
            return {nullptr,nullptr};
    }

  public:
    void flatten(TreeNode* root) {
        pre = nullptr;
        preorder(root);
    }
};

int main()
{
    Solution s;
    auto tree = make_tree({1,null,2,3});
    println(tree);
    s.flatten(tree);
    println(tree);
    free_tree(tree);
    return 0;
}
