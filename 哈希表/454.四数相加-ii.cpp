/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
  {
      unordered_map<int, int> umap;
      for (auto i : nums1)
      {
          for (auto j : nums2)
          {
              umap[i + j]++;
          }
      }
      int res = 0;
      for (auto i : nums3)
      {
          for (auto j : nums4)
          {
              if (umap.find(0 - (i + j)) != umap.end())
              {
                  res += umap[0 - (i + j)];
              }
          }
      }
      return res;
  }
};
// @lc code=end

