/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        queue<TreeNode *> que;
        if (root)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            int size = que.size();
            vector<int> path;
            for (int i = 0; i < size; i++)
            {
                TreeNode *top = que.front();
                que.pop();
                path.push_back(top->val);
                if (top->left)
                    que.push(top->left);
                if (top->right)
                    que.push(top->right);
            }
            res.push_back(path);
        }
        return res;
    }
};
// @lc code=end
