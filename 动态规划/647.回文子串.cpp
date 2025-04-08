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
    int countSubstrings1(string s)
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
	/* 
		要求s的回文子串的个数，是连续的
		定义dp[i][j]用来规定s的子串[i,j]是否是回文
		如果j==i,肯定是,放在初始化里面，因为要符合区间的定义
		如果j-i==1,如果s[i]==s[j]那才是
		其实要判断s[i]==s[j],如果不相等，根本不用管
		如果j-i>1,dp[i][j]=dp[i+1][j-1],这样收缩区间了
		因为dp[i][j]=dp[i+1][j-1]，是从左下方过来的，因此i这个维度要从后往前遍历
	*/
	int countSubstrings(string s) {
		int n = s.size();
		int res=0;
		vector<vector<bool>> dp(n+1,vector(n+1,false));
		for(int i=0;i<n;i++){
			dp[i][i]=true;
		}
		for(int i=n-2;i>=0;i--){
			for(int j=i+1;j<n;j++){
				if(s[i]==s[j]){
					if(j-i==1){
						dp[i][j]=true;
					}else if(j-i>1){
						dp[i][j]=dp[i+1][j-1];
					}
				}
			}
		}
		for(auto vec:dp){
			for(auto istrue:vec){
				if(istrue){
					res++;
				}
			}
		}
		return res;
	}
};
// @lc code=end
