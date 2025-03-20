/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        // 我直接tm迭代法暴力点遍历,后序简单点，左右中->中右左
        // 按理来说这种中整个树中找符合要求的节点应该都可以用迭代，如果中间涉及计算了就不太适合
        stack<TreeNode *> st;
        int res = 0;
        if (root == nullptr)
            return res;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *top = st.top();
            if (top)
            {
                st.push(nullptr);
                if (top->left && !top->left->left && !top->left->right)
                {
                    res += top->left->val;
                }
                // 上面是中的处理逻辑
                if (top->right)
                    st.push(top->right);
                if (top->left)
                    st.push(top->left);
            }
            else
            {
                st.pop();
                st.pop();
            }
        }
        return res;
    }
};
// @lc code=end
