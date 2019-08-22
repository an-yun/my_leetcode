#include "zuo/ioutils.hpp"
#include "zuo/treenode.hpp"
#include <vector>
#include <algorithm>
#include <numeric>

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
    int maxPath;
    int post_order(TreeNode* root)
    {
        if(root)
        {
            int l = post_order(root->left);
            int r = post_order(root->right);
            int from_root =  max(max(l + root->val, r + root->val ), root->val);
            maxPath = max(maxPath, max(from_root, l+r+root->val));
            return from_root;
        }
        return 0;
    }

  public:
    int maxPathSum(TreeNode* root) {
        maxPath = numeric_limits<int>::min();
        post_order(root);
        return maxPath;
    }
};

int main()
{
    Solution s;
    TreeNode *tree = make_tree({-10, 9, 20, null, null, 15, 7});
    println(s.maxPathSum(tree));
    free_tree(tree);
    return 0;
}
