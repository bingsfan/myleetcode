/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    void travel(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        swap(node->left, node->right);
        if (node->left)
            travel(node->left);
        if (node->right)
            travel(node->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        // 翻转二叉树，想的是直接中序递归遍历就行了
        travel(root);
        return root;
    }
};
// @lc code=end
