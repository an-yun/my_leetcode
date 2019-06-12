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
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> level_travel;
        if (root)
        {
            list<TreeNode *> node_q({root});
            while (!node_q.empty())
            {
                vector<int> level;
                TreeNode *node;
                TreeNode * layer_end = node_q.back();
                do
                {
                    node = node_q.front();
                    node_q.pop_front();
                    level.push_back(node->val);
                    if(node->left)
                        node_q.push_back(node->left);
                    if(node->right)
                        node_q.push_back(node->right);                        

                } while (node != layer_end);
                level_travel.push_back(level);
            }
        }
        reverse(level_travel.begin(), level_travel.end());
        return level_travel;
    }
};

int main()
{
    Solution s;
    auto tree = make_tree({3, 9, 20, null, null, 15, 7});
    println(s.levelOrderBottom(tree));
    free_tree(tree);
    return 0;
}
