/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    这题我总觉得跟监控二叉树很像，其实确实很像，就是树上相邻的节点不能要
    先随便分析一下，如果当前节点选择了偷，那么他的父节点，和两个子节点都不能要
    如果当前节点不选择偷，那两个子节点可以选择一个偷了
    父节点这里就不管了，因为父节点肯定处理过了

    不对不对，这题我想不出来了，这是个树形dp
    定义返回值是dp数组，0代表不偷，1代表偷，肯定是后序遍历，因为要从下而上
  */

    vector<int> travel(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {0, 0};
        }
        vector<int> left = travel(node->left);
        vector<int> right = travel(node->right);
        // 如果不偷当前节点,那左右节点都是可偷可不偷的
        int val1 = max(left[0], left[1]) + max(right[0], right[1]);
        // 如果偷了，那左右节点都不要
        int val2 = node->val + right[0] + left[0];
        return {val1, val2};
    }
    int rob(TreeNode *root)
    {
        vector<int> res = travel(root);
        return max(res[0], res[1]);
    }
};
// @lc code=end
