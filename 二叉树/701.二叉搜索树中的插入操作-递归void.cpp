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
    TreeNode *parent;
    void travel(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            TreeNode *node = new TreeNode(val);
            if (val > parent->val)
            {
                parent->right = node;
            }
            else
            {
                parent->left = node;
            }
            return;
        }
        parent = root;
        if (root->val > val)
        {
            travel(root->left, val);
        }
        if (root->val < val)
        {
            travel(root->right, val);
        }
    }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // 我的想法是先找到位置，然后插入？parent记录要插入位置的父节点
        // 那得找到叶子结点才能插入，而最后返回的要求是根结点，差不多要遍历整棵树，void就行？
        parent=new TreeNode(-1);
        if(root==nullptr){
            return new TreeNode(val);
        }
        travel(root, val);
        return root;
    }
};
// @lc code=end
