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
  private:
    vector<int> path;
    int r_sum;
    void collect_path(TreeNode *root, vector<vector<int>> &paths)
    {
        if (root)
        {
            r_sum -= root->val;
            path.push_back(root->val);
            if (root->left || root->right)
            {
                collect_path(root->left, paths);
                collect_path(root->right, paths);
            }
            else if (r_sum == 0)
                paths.push_back(path);
            r_sum += root->val;
            path.pop_back();
        }
    }

  public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> paths;
        path.clear();
        r_sum = sum;
        collect_path(root, paths);
        return paths;
    }
};

int main()
{
    Solution s;
    auto tree = make_tree({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1});
    println(s.pathSum(tree, 22));
    free_tree(tree);
    return 0;
}
