/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution
{
  public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        if(s.size()==0){
            return 0;
        }
        sort(s.begin(), s.end());
        int res = 0;
        int sIndex = s.size() - 1;
        for (int i = g.size() - 1; i >= 0;i--)
        {
            if (sIndex>=0&&g[i] <= s[sIndex])
            {
                res++;
                sIndex--;
                // if(sIndex>0){
                //     sIndex--;
                // }else{
                //     return res;
                // }
            }
        }
        return res;
    }
};
// @lc code=end
