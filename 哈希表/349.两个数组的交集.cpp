/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution
{
  public:
    /*
    将nums1中的数加入一个集合中
    遍历nums2，看nums2中的数是不是在这个集合中，如果在就加入结果中
    可能集合中会重复，那我在再一个uset,收集结果，返回的时候再转换成vector
*/
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> uset;
        unordered_set<int> res_set;
        for (auto num : nums1)
        {
            uset.insert(num);
        }
        for (auto num : nums2)
        {
            if (uset.count(num))
            {
                res_set.insert(num);
            }
        }
        return vector<int>(res_set.begin(), res_set.end());
    }
};
// @lc code=end
