/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
//   这道题做的很不熟练
    bool backtrace(TreeNode *node, int &sum, int target)
    {
        if (sum == target && !node->left && !node->right)
        {
            return true;
        }
        if (!node->left && !node->right && sum != target)
        {
            return false;
        }
        if (node->left)
        {
            sum += node->left->val;
            if(backtrace(node->left, sum, target)) return true;
            sum -= node->left->val;
        }
        if (node->right)
        {
            sum += node->right->val;
            if(backtrace(node->right, sum, target)) return true;
            sum -= node->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if(root==nullptr) return false;
        // 要遍历整条树，还带回溯，我感觉前序才带回溯
        if (backtrace(root, root->val, targetSum))
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
