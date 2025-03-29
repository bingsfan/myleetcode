/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
  public:
    /*
    这道题和一和零那道题很像，都是用字符串填充
    物品就是wordDict，背包就是s，要求的是能否用物品装满s
    dp[i]:字符串长度为i，dp[i]如果为true，说明可以拆分成一个或多个在字典中的单词
    如果dp[j-1]为true，且[j,i]这个子串在worddict中出现的话，dp[i]=true
    dp[0]=true  不然没有结果了，全是false
    这是个排列问题，要先背包后物品
    返回值是dp[s.size()-1]

    这题我在处理的时候为了保证dp数组和s的下标统一，直接给字符串新插入了一个字符，然后遍历j的时候
    最好能遍历到i，这样能解决只有一个字符的情况，i和j都从1开始遍历，因为最开始添加的字符不用管
    这个题和一和零那道到时候还得再看看，对于这种字符串类型的背包问题有点不够熟练
  */
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(1001, false);
        unordered_set<string> uset(wordDict.begin(),wordDict.end());
        dp[0] = true;
        s.insert(s.begin(), ' ');
        for (int i = 1; i < s.size(); i++)
        {
            for (int j = 1; j <= i; j++)
            {
                string substr = s.substr(j, i - j + 1);
                if (dp[j - 1] == true && uset.count(substr))
                {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size() - 1];
    }
};
// @lc code=end
