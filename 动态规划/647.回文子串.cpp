/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution
{
  public:
    // bool isValid(string s, int i, int j)
    // {
    //     if (i == j)
    //     {
    //         return true;
    //     }
    //     int left = i, right = j;
    //     while (left <= right)
    //     {
    //         if (s[left] != s[right])
    //         {
    //             return false;
    //         }
    //         left++;
    //         right--;
    //     }
    //     return true;
    // }
    // int countSubstrings(string s)
    // {
    //     int res = 0;
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         for (int j = i; j < s.size(); j++)
    //         {
    //             if (isValid(s, i, j))
    //             {
    //                 res++;
    //             }
    //         }
    //     }
    //     return res;
    // }
    int countSubstrings(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            res++;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1 || dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
