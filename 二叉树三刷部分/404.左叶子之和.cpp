/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
        直接就用这个函数应该就行，要想清楚这个递归函数的返回值是什么，函数的含义是什么
        和dp数组的定义很类似,想想递归中止条件先
        如果root空，return 0
        什么时候是左叶子节点？
        root->left&&!root->left->left&&!root->left->right
        这个时候应该return root->left->val？
    */
    int sumOfLeftLeaves(TreeNode *root)
    {
        int res=0;
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left && !root->left->left && !root->left->right)
        {
            res+= root->left->val;
        }
        int left = sumOfLeftLeaves(root->left);
        int right = sumOfLeftLeaves(root->right);
        return left + right+res;
    }
};
// @lc code=end
