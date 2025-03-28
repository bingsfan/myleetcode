/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
  /*
  这个只用返回它到不到得了最后，和跳跃游戏2不太一样，因为2的数组一定能到
  只要判断当前这个节点能到的范围是不是>=数组下标就行，数组长度>=1,先把边界一处理
*/
  bool canJump(vector<int> &nums)
  {
      if (nums.size() == 1)
      {
          return true;
      }
      int end = 0;
      for (int i = 0; i <= end; i++)
      {
          end = max(end, i + nums[i]);
          if (end >= nums.size() - 1)
          {
              return true;
          }
      }
      return false;
  }
};
// @lc code=end

