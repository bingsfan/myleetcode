/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
    回文字符串是正着读和倒过来读一样的字符串。
    子字符串是字符串中的由连续字符组成的一个序列。
 */

// @lc code=start
class Solution {
public:
    /*
        dp数组定义：
            错误想法：应该定义dp[i]，是字符串s的前i个元素中回文子串的个数（想错啦，要定义成二维的）
            布尔类型的dp[i][j]：表示区间范围[i,j]
            （注意是左闭右闭）的子串是否是回文子串，如果是dp[i][j]为true，否则为false。

        递推公式：
            如果s[i]==s[j]才能继续进行下去
                如果i==j  比如a dp[i][j]=1
                如果j-i==1 比如aa dp[i][j]=1
                如果j-i>1了 比如cabac，就要判断dp[i+1][j-1]

        遍历顺序：
            因为有dp[i+1][j-1]是从左下方推出来的
            因此i要从后往前遍历，j从前往后遍历
        
        初始化：全部为false
    */
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int res=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i<=1){
                        res++;
                        dp[i][j]=true;
                    }else if(dp[i+1][j-1]){
                        res++;
                        dp[i][j]=true;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

