/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
  public:
    struct mycompare
    {
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return a.second > b.second; // 小顶堆用大于号
        }
    };
    // 频率，得先对频率进行排序，得用map统计频率,我先对map的频率进行排序，然后转成一个vec，取前k个就行了
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;
        for (auto num : nums)
        {
            umap[num]++;
        }
        // 不排序了，我直接用一个优先级队列维护
        // 大顶堆还是小顶堆？大的话pop最大的直接就pop了，我要让小的滚蛋，之后留下的就是前k个最大的了
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> pq;
        // 将umap中的元素加入一个大小为k的优先级队列中去
        for (auto it = umap.begin(); it != umap.end(); it++)
        {
            pq.push(*it);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty())
        {
            int num = pq.top().first;
            res.push_back(num);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
