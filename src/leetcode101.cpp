#include "zuo/treenode.hpp"

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
    bool isSymmetricSubTree(TreeNode *tree1, TreeNode* tree2)
    {
        if(tree1 && tree2) 
            return tree1->val == tree2->val 
                && isSymmetricSubTree(tree1->left, tree2->right)
                && isSymmetricSubTree(tree1->right, tree2->left);
        else if(tree1 || tree2) return false;
        else return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root) return isSymmetricSubTree(root->left, root->right);
        return true;    
    }
};

int main()
{
    Solution s;
    auto tree1 = make_tree({1,2,2,3,4,4,3}),tree2 = make_tree({1,2,3,null,3,null,3});
    println(s.isSymmetric(tree1));
    println(s.isSymmetric(tree2));
    free_tree(tree1);
    free_tree(tree2);
    return 0;
}
