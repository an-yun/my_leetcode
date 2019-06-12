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
    size_t isBalancedHeight(TreeNode* root) {
        if(root)
        {
            size_t l_height = isBalancedHeight(root->left);
            size_t r_height = isBalancedHeight(root->right);
            if(l_height && r_height)
            {
                if(l_height + 1 < r_height || r_height + 1 < l_height)
                    return 0;
                else
                    return max(l_height, r_height) + 1;
            }
            else
                return 0;
        }
        return 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedHeight(root) != 0;
    }
};

int main()
{
    Solution s;
    auto tree1 = make_tree({3, 9, 20, null, null, 15, 7});
    auto tree2 = make_tree({1,2,2,3,3,null,null,4,4});
    println(tree1, "is balanced?", s.isBalanced(tree1));
    println(tree2, "is balanced?", s.isBalanced(tree2));
    free_tree(tree1);
    free_tree(tree2);
    return 0;
}
