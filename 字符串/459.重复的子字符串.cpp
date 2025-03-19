/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution
{
  public:
    void getNext(int *next, string &s)
    {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++)
        {
            while (s[j] != s[i] && j > 0)
            {
                j = next[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        vector<int> next(n, 0);
        getNext(next.data(), s);
        int len = next[n - 1]; // 最长相同前缀和后缀的长度

        // 如果 len > 0 且 n % (n - len) == 0，则说明字符串可以由某个子串重复多次构成
        return n % (n - len) == 0 && len > 0;
    }
};
// @lc code=end
