/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution
{
  public:
    /*
    这题肯定也是要排序的，但是对什么排序呢？
    因为要求前面人的身高大于等于当前的，因此先对身高从大到小排，如果相等按照k排
    先把特殊值一处理,然后排序
    排序完直接按照k的值去插入,注意insert的第一个参数是迭代器
  */
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        if (people.size() == 1)
        {
            return people;
        }
        vector<vector<int>> res;
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0])
            {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });
        int pos;
        for (int i = 0; i < people.size(); i++)
        {
            pos = people[i][1];
            res.insert(res.begin() + pos, people[i]);
        }
        return res;
    }
};
// @lc code=end
