/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
  /* 
    都勾八用的后序，有点分不清了说实话
    这个和最大深度相比主要是要分左右子树如果分别不存在的情况
    两个深度问题层序都可以解决，直接改一下代码模板就行了
  */
    int getDepth(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        if (node->left && !node->right)
        {
            return 1 + getDepth(node->left);
        }
        else if (!node->left && node->right)
        {
            return 1 + getDepth(node->right);
        }
        return 1 + min(getDepth(node->left), getDepth(node->right));
    }
    int minDepth(TreeNode *root)
    {
        return getDepth(root);
    }
};
// @lc code=end
