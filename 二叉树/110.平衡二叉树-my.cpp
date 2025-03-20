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
        int right = getHeight(node->right);
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode *root)
    {
        if (root==nullptr)
        {
            return true;
        }
        
        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);
        if (abs(leftH - rightH) > 1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end
