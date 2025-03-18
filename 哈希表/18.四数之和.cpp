/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution
{
  public:
    /*
    target可以为负数，思路和三数之和差不多，多了一层循环
    被这沙比溢出折腾半天，在去重的逻辑上，j的范围设置有点问题，j应该>i+1
    直接用long long或者int64_t来处理溢出的问题
  */
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (target >= 0 && nums[i] > target)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (target >= 0 && nums[i] + nums[j] > target)
                {
                    break;
                }
                if (j > i+1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    int64_t sum = (int64_t)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target)
                    {
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
