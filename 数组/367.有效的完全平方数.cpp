/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
 public:
  bool isPerfectSquare(int num) {
    int l = 0;
    int r = num;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if ((size_t)m * m == num) {
        return true;
      } else if ((size_t)m * m < num) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return false;
  }
};
// @lc code=end
