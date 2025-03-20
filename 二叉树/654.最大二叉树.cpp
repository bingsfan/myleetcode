/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *build(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }
        // 找最大值造根节点,找出最大值和最大索引
        int rootVal = -1;
        int index;
        for (int i = 0; i < nums.size(); i++)
        {
            if (rootVal < nums[i])
            {
                index = i;
                rootVal = nums[i];
            }
        }
        TreeNode *root = new TreeNode(rootVal);
        // 切割数组
        vector<int> left(nums.begin(), nums.begin() + index);
        vector<int> right(nums.begin() + index + 1, nums.end());
        // 递归左右子树
        root->left = build(left);
        root->right = build(right);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return build(nums);
    }
};
// @lc code=end
