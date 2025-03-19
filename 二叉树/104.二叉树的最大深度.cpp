/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
        // 求根节点高度肯定是后序
        if (node == nullptr)
        {
            return 0;
        }
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        return 1 + max(left, right);
    }
    int maxDepth(TreeNode *root)
    {
        int res;
        res = getHeight(root);
        return res;
    }
};
// @lc code=end
