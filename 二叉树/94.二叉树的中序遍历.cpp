/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        // 处理方式和前序一样，中序：左中右，栈：右中左
        vector<int> res;
        stack<TreeNode *> st;
        if (root)
            st.push(root);
        while (!st.empty())
        {
            TreeNode *top = st.top();
            if (top)
            {
                st.pop();
                if (top->right)
                    st.push(top->right);
                st.push(top);
                st.push(nullptr);
                if (top->left)
                    st.push(top->left);
            }
            else
            {
                st.pop();
                top = st.top();
                st.pop();
                res.push_back(top->val);
            }
        }
        return res;
    }
};
// @lc code=end
