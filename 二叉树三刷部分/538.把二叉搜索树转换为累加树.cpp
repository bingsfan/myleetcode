/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    因为是要从最大的节点开始遍历，遍历顺序要是右中左
*/
    void travel(TreeNode *root, int &sum)
    {
        if (root == nullptr)
        {
            return;
        }
        travel(root->right, sum);
        sum += root->val;
        root->val = sum;
        travel(root->left, sum);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        // 这里要返回的是根节点，没必要用这个函数
        int sum = 0;
        travel(root, sum);
        return root;
    }
};
// @lc code=end
