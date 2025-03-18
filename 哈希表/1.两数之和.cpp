/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
      vector<int> res;
      unordered_map<int, int> umap;
      for (int i = 0; i < nums.size(); i++)
      {
          umap[nums[i]] = i;
      }
      for (int i = 0; i < nums.size(); i++)
      {
          int k1 = nums[i];
          if (umap.count(target - k1) && i != umap[target - k1])
          {
              return {i, umap[target - k1]};
          }
      }
      return res;
  }
};
// @lc code=end

