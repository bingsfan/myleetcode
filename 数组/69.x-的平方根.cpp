/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
/* 
    这里要求的是k平方小于等于x的最大的k值，实际上是求上界
*/
    int mySqrt(int x)
    {
        int left = 1;
        int right = x;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if ((long long)mid * mid <= x)
            {
                left = mid + 1;
            }
            else
            {
                right=mid-1;
            }
        }
        return left - 1;
    }
};
// @lc code=end

