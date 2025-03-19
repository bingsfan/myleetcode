/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int travel(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left = travel(node->left);
        int right = travel(node->right);
        return 1 + left + right;
    }
    int countNodes(TreeNode *root)
    {
        return travel(root);
    }
};
// @lc code=end
