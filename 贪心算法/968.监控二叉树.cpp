/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    这题真他吗的难，还想不明白呢
  */
    int res = 0;
    int travel(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 1;
        }
        int left = travel(node->left);
        int right = travel(node->right);
        if (left == 0 || right == 0)
        {
            res++;
            return 2;
        }
        if (left == 2 || right == 2)
        {
            return 1;
        }
        // 子节点都被覆盖，但是根节点没有被覆盖
        return 0;
    }
    int minCameraCover(TreeNode *root)
    {
        int rootstate = travel(root);
        if (rootstate == 0)
        {
            res++;
        }
        return res;
    }
};
// @lc code=end
