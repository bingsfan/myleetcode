/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // 再练练二叉搜索树的迭代遍历,这个要简单一点
        if(root==nullptr){
            TreeNode *node = new TreeNode(val);
            return node;
        }
        TreeNode *cur = root;
        TreeNode *parent;
        while (cur)
        {
            parent = cur;
            if (cur->val > val)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        TreeNode *node = new TreeNode(val);
        if (parent->val > val)
        {
            parent->left = node;
        }
        else
        {
            parent->right = node;
        }
        return root;
    }
};
// @lc code=end
