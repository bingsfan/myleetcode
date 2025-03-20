/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
  public:
    void traceback(TreeNode *node, vector<int> &path, vector<string> &res)
    {
        if (!node->left && !node->right)
        {
            string spath;
            for (int i = 0; i < path.size() - 1; i++)
            {
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size() - 1]);
            res.push_back(spath);
            return;
        }
        if (node->left)
        {
            path.push_back(node->left->val);
            traceback(node->left, path, res);
            path.pop_back();
        }
        if (node->right)
        {
            path.push_back(node->right->val);
            traceback(node->right, path, res);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        vector<int> path;
        path.push_back(root->val);
        traceback(root, path, res);
        return res;
    }
};
// @lc code=end
