/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution
{
  public:
    // 输入：tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
    // 输出：["JFK","MUC","LHR","SFO","SJC"]
    // 输入：tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    // 输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
    // 解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"] ，但是它字典排序更大更靠后。
    // 所有机票都必须用一次，我要对tickets的to排序
    // 这题有点难啊
    unordered_map<string, map<string, int>> umap;
    vector<string> res;
    bool traceback(int num)
    {
        if (num+1 == res.size() )
        {
            return true;
        }
        for (auto &target : umap[res.back()])
        {
            if (target.second > 0){
                res.push_back(target.first);
                target.second--;
                if (traceback(num))
                    return true;
                target.second++;
                res.pop_back();
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        umap.clear();
        res.clear();
        for (auto vec : tickets)
        {
            umap[vec[0]][vec[1]]++;
        }
        res.push_back("JFK");
        traceback(tickets.size());
        return res;
    }
};
// @lc code=end
