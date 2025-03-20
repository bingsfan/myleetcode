/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode *root)
    {
        // 直接层序遍历，找最后一层的第一个值就行了
        int res = 0;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            res = que.front()->val;
            for (int i = 0; i < size; i++)
            {
                TreeNode *top = que.front();
                que.pop();
                if (top->left)
                    que.push(top->left);
                if (top->right)
                    que.push(top->right);
            }
        }
        return res;
    }
};
// @lc code=end
