#include "zuo/treenode.hpp"
#include <limits>

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
private:
    bool value_set;
    bool inorder_traversal(TreeNode *root, int& value)
    {
        if(root)
        {
            if(!inorder_traversal(root->left, value)) return false;
            if(value_set && value >= root->val) return false;
            value = root->val;
            value_set = true;
            return inorder_traversal(root->right,value);
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        value_set = false;
        int value ;
        return inorder_traversal(root, value);
    }
};

int main()
{
    Solution s;
    auto tree1 = make_tree({2,1,3}), tree2 = make_tree({5,1,4,null,null,3,6});
    println(tree1);
    println("tree1 is valid BST?", s.isValidBST(tree1));
    println(tree2);
    println("tree2 is valid BST?", s.isValidBST(tree2));
    return 0;
}
