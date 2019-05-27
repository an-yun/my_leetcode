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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p)
        {
            if(q) return p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
            return false;
        }
        else if (!q) return true;
        else return false;
    }
};

int main()
{
    Solution s;
    auto p = make_tree({1,2,3}),q = make_tree({1,2,3});
    println(s.isSameTree(p,q));
    auto p1 = make_tree({1,2}), q1 = make_tree({1,null,2});
    println(s.isSameTree(p1,q1));
    free_tree(p);
    free_tree(q);
    free_tree(p1);
    free_tree(q1);
    return 0;
}
