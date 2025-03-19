/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        // 写统一迭代法把，递归没啥意思了，使用空指针标记法，对于中节点出栈但没有处理的之后要加进去，之后再给他加个空指针
        // 前序顺序：中左右，但是要考虑栈的顺序，需要右左中
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
                    st.push(top->right); // 右
                if (top->left)
                    st.push(top->left); // 左
                st.push(top);           // 这是中间节点的处理逻辑，还要加上nullptr
                st.push(nullptr);
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
