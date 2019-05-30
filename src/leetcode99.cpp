#include "zuo/treenode.hpp"

using namespace std;

/**
 * Definition for a binary tree node.
 *  struct TreeNode {
 *  int val;
 *  TreeNode *left;
 *  TreeNode *right;
 *  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *}; 
 */
class Solution {
    private:
        TreeNode *pre;
        TreeNode *swap_node;
        void inorder_recover(TreeNode *root)
        {
            if(root)
            {
                inorder_recover(root->left);
                if(pre && pre->val > root->val)
                {
                    if(swap_node) swap(root->val, swap_node->val);
                    else swap_node = pre;
                }
                pre = root;
                inorder_recover(root->right);
            }
        }
    public:
        void recoverTree(TreeNode* root) {
            pre = nullptr;
            swap_node = nullptr;
            inorder_recover(root);
        }

};

int main()
{
    Solution s;
    auto tree1 = make_tree({1,3,null,null,2}),tree2 = make_tree({3,1,4,null,null,2});
    s.recoverTree(tree1);
    println(tree1);
    println(to_string(tree1));
    s.recoverTree(tree2);
    println(tree2);
    println(to_string(tree2));
    free_tree(tree1);
    free_tree(tree2);
    return 0;
}
