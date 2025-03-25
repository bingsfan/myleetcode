/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution
{
  public:
    vector<vector<string>> res;
    // 这里面的一个string代表了一行
    bool isvalid(vector<string> &board, int row, int col, int n)
    {
        // 不能同列
        for (int i = 0; i < n; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }
        // 不能同斜线
        int i = row, j = col;
        while (i >= 0 && j >= 0)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j--;
        }
        i = row, j = col;
        while (i >= 0 && j < n)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void traceback(vector<string> &board, int n, int row)
    {
        if (n == row)
        {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
        { // 每次的选择，那一列放q
            if (isvalid(board, row, col, n))
            {
                board[row][col] = 'Q';
                traceback(board, n, row + 1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        traceback(board, n, 0);
        return res;
    }
};
// @lc code=end
