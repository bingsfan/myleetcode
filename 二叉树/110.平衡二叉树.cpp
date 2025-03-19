/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int getHeight(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left = getHeight(node->left);
        if (left == -1)
            return -1;
        int right = getHeight(node->right);
        if (right == -1)
            return -1;
        int res = abs(left - right);
        if (res > 1)
        {
            res = -1;
        }
        else
        {
            res = 1 + max(left, right);
        }
        return res;
    }
    bool isBalanced(TreeNode *root)
    {
        if (getHeight(root) == -1)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
