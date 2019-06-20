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
    int minDepth(TreeNode* root) {
        if(root)
        {
            int l = minDepth(root->left);
            int r = minDepth(root->right);
            if(l && r) return 1 + min(l,r);
            else return 1+l+r;
        }
        else return 0;
    }
};

int main()
{
    Solution s;
    auto tree = make_tree({3,9,20,null,null,15,7});
    println(s.minDepth(tree));
    free_tree(tree);
    return 0;
}
