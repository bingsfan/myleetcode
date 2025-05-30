/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if(root==nullptr||root->val==val){
            return root;
        }
        TreeNode *res;
        if (root->val > val)
        {
            res=searchBST(root->left, val);
        }
        if (root->val < val)
            res=searchBST(root->right, val);
        return res;
    }
};
// @lc code=end
