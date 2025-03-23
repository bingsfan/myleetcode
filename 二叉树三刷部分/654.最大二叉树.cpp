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
    /*
        这题还是得用带返回值的递归，而且因为要找最大值，还要有区间的范围，统一规定为，左闭右闭区间
        这个的返回值就和上一个的不一样了，因为多了left和right，left>right才滚蛋
        我灵光一闪感觉不要left，right也行，对了就完事儿了，就jb仿照上一个题
    */

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.empty())
        {
            return nullptr;
        }
        int max = INT_MIN;
        int index;
        // 这就找到最大值了
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                index = i;
            }
        }
        // 然后开始分割数组
        vector<int> left(nums.begin(), nums.begin() + index);
        vector<int> right(nums.begin() + index + 1, nums.end());

        TreeNode *root = new TreeNode(max);
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};
// @lc code=end
