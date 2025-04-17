/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution
{
  public:
    /*
        单调栈主要解决的就是这种求下一个更大元素的位置，和值，这个题多了一步
        因为要在nums2中找，nums1是nums2的子集，因此提前处理好nums2中的每个元素，之后光查就行了
    */
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> umap;
        for (auto num : nums2)
        {
            umap[num] = -1;
        }
        // 遍历nums2，找它每一个元素的下个更大元素的值，不是索引，使用单调栈，存储在umap中
        // 前面那个题栈中存的是值和索引，这个好像没必要索引了，因为map中存储的两个也都是值，跟索引没啥关系
        stack<int> st;
        int n2 = nums2.size();
        int n1 = nums1.size();
        for (int i = 0; i < n2; i++)
        {
            while (!st.empty() && nums2[i] > st.top())
            {
                umap[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int> res(n1, -1);
        for (int i = 0; i < n1; i++)
        {
            res[i] = umap[nums1[i]];
        }
        return res;
    }
};
// @lc code=end
