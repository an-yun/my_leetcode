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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root)
        {
            int n_sum = sum - root->val;
            if (root->left || root->right)
                return hasPathSum(root->left, n_sum) || hasPathSum(root->right, n_sum);
            else
                return n_sum == 0;
        }
        else return false;
    }
};

int main()
{
    Solution s;
    auto tree = make_tree({5,4,8,11,null,13,4,7,2,null,null,null,1});
    println(s.hasPathSum(tree, 26));
    free_tree(tree);
    return 0;
}
