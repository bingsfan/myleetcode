/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *delete1node(TreeNode *node)
    {
        if (!node->left && !node->right)
        {
            return nullptr;
        }
        else if (!node->left && node->right)
        {
            return node->right;
        }
        else if (node->left && !node->right)
        {
            return node->left;
        }
        else
        {
            // 要删除的元素左右子树都不为空的情况，我要用node的左子树的最大元素去替代当前的node,第一种写法
            // 这种写法更加简单粗暴一点，直接把node的右子树全部加到node->left中的最大值右边去

            
            // TreeNode *cur = node->left;
            // while (cur->right)
            // {
            //     cur = cur->right;
            // }
            // cur->right = node->right;
            // return node->left;


            // 第二种写法
            // 要删除的元素左右子树都不为空的情况，我要用node的左子树的最大元素去替代当前的node
            TreeNode *cur = node->left;
            TreeNode *parent = node; // 记录cur的父节点
            while (cur->right)
            {
                parent = cur;
                cur = cur->right;
            }
            // 将cur的值赋给node
            node->val = cur->val;

            // 删除cur节点
            if (parent == node)
            {
                // 如果cur是parent的左子节点（特殊情况：cur没有右子树）
                parent->left = cur->left;
            }
            else
            {
                // cur是parent的右子节点
                parent->right = cur->left;
            }
            delete cur; // 释放cur节点的内存
            return node;
        }
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *cur = root;
        TreeNode *parent = nullptr;
        if (root == nullptr)
        {
            return nullptr;
        }
        // 如果parent==nullptr说明要删除的就一个根节点，但它可能是三种情况都包含的
        while (cur)
        {
            if (cur->val == key) break;
            parent = cur;
            if (cur->val > key)
            {
                cur = cur->left;
            }
            else
                cur = cur->right;
        }
        if (parent == nullptr)
        {
            // 那需要直接返回一个新的树，没法通过parent去操作了
            return delete1node(cur);
        }
        if (parent->left && parent->left->val == key)
        {
            parent->left = delete1node(cur);
        }
        if (parent->right && parent->right->val == key)
        {
            parent->right = delete1node(cur);
        }
        return root;
    }
};
// @lc code=end
