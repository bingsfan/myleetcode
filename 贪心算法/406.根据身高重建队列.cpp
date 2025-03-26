/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution
{
  public:
//   数组的写法，还是数组好看一点
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<vector<int>> res;
        for (int i = 0; i < people.size(); i++)
        {
            int pos = people[i][1];
            res.insert(res.begin() + pos, people[i]);
        }
        return res;
    }

    // 链表的写法
    // vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    // {
    //     sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
    //         if (a[0] == b[0])
    //             return a[1] < b[1];
    //         return a[0] > b[0];
    //     });
    //     list<vector<int>> res;
    //     for (int i = 0; i < people.size(); i++)
    //     {
    //         int pos = people[i][1];
    //         auto it = res.begin();
    //         while (pos--)
    //         {
    //             it++;
    //         }
    //         res.insert(it, people[i]);
    //     }
    //     return vector<vector<int>>(res.begin(), res.end());
    // }
};
// @lc code=end
