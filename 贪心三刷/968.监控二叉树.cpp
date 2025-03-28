/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int res = 0;
    int travel(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 1;
        }
        int left = travel(node->left);
        int right = travel(node->right);
        if (left == 0 || right == 0)
        {
            res++;
            return 2;
        }
        if (left == 2 || right == 2)
        {
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode *root)
    {
        int rootstate = travel(root);
        if (rootstate == 0)
        {
            res++;
        }
        return res;
    }
};
// @lc code=end
