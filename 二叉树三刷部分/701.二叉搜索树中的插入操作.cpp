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
    /*
        先写一个迭代，比较容易，练练手把
        要用一个parent来记录，要删除/添加节点的父节点
    */
#if 0
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
        {
            return new TreeNode(val);
        }
        TreeNode *parent;
        TreeNode *cur = root;
        while (cur)
        {
            parent=cur;
            // 这里parent记录之前的cur
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
#endif
#if 1
    /*
    下面写一个递归的方法，如果BST遍历的当前节点为空的话，其实就是我们要插入的节点位置了，
    如果是说删除或者搜索，那就得完全相等，目前这么理解的
    带返回值直接就用这个函数就行了
    */
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        return root;
    }
#endif
};
// @lc code=end
