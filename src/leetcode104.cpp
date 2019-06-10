#include <algorithm>
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
    int maxDepth(TreeNode* root) {
        if(root) return 1 + max(maxDepth(root->left), maxDepth(root->right));
        else return 0;
    }
};

int main()
{
    Solution s;
    auto tree = make_tree({3,9,20,null,null,15,7});
    println(s.maxDepth(tree));
    return 0;
}
