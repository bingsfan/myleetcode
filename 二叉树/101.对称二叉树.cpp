/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool travel(TreeNode *t1, TreeNode *t2)
    {
        if (t1 && !t2 || t2 && !t1)
        {
            return false;
        }
        if (!t1 && !t2)
        {
            return true;
        }
        if (t1->val == t2->val)
        {
            return travel(t1->left, t2->right) && travel(t1->right, t2->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode *root)
    {
        // 给你一个二叉树的根节点 root ， 检查它是否轴对称。
        return travel(root->left, root->right);
    }
};
// @lc code=end
