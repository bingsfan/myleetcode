/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
  public:
    // 频率，得先对频率进行排序，得用map统计频率,我先对map的频率进行排序，然后转成一个vec，取前k个就行了
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;
        for (auto num : nums)
        {
            umap[num]++;
        }
        vector<pair<int, int>> vec_map(umap.begin(), umap.end());
        sort(vec_map.begin(), vec_map.end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(vec_map[i].first);
        }
        return res;
    }
};
// @lc code=end
