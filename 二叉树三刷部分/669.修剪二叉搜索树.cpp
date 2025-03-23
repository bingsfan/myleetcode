/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    如果root节点大于high，那root和右子树都不要
    如果root节点小于low，那root和左子树都不要
    这是处理逻辑，终止逻辑呢？
*/
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        // 这两个if是用来处理根节点的
        if (root->val > high)
        {
            return trimBST(root->left, low, high);
        }
        if (root->val < low)
        {
            return trimBST(root->right, low, high);
        }
        // 如果根节点没事，还要判断左右子树，这里体现了前序
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
// @lc code=end
