#include <algorithm>
#include <vector>
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
    vector<int> *preorder;
    vector<int> *inorder;
    TreeNode *buildTree(size_t p_b, size_t p_e, size_t i_b, size_t i_e)
    {
        if(p_b >= p_e)
            return nullptr;
        else
        {

            auto root = (*preorder)[p_b];
            size_t p;
            for (p = i_b; p < i_e;++p)
            {
                if((*inorder)[p] == root)
                    break;
            }
            auto tree = new TreeNode(root);
            tree->left = buildTree(p_b + 1, p_b + p - i_b+1, i_b, p);
            tree->right = buildTree(p_b + p - i_b + 1, p_e, p + 1, i_e);
            return tree;
        }
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        size_t n = preorder.size();
        if(n)
        {
            this->preorder = &preorder;
            this->inorder = &inorder;
            return buildTree(0, n, 0, n);
        }
        else
            return nullptr;
    }
};

int main()
{
    Solution s;
    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};
    println(s.buildTree(preorder, inorder));
    return 0;
}