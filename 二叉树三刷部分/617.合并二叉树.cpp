/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
        如果两个都有值，都加到r1；
        如果r2有值，r1空，r1直接等于r2,return r2
        如果r1有值，r2空,return r1
        这题我想的可太有问题的，草,因为这是两个参数，跟一个参数还不一样，tmd
        直接两道if分别卡住r1和r2为空的情况，就算都为空也只能返回空了
        但我的思路问题好像也不大,把情况分好就行了
    */
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
        {
            return nullptr;
        }
        else if (!root1 && root2)
        {
            return root2;
        }
        else if (root1 && !root2)
        {
            return root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
// @lc code=end
