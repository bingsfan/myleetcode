/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution
{
  public:
    bool isvalid(vector<vector<char>> &board, int row, int col, char val)
    {
        // 同行不能要
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == val)
            {
                return false;
            }
        }
        // 同列不能要
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == val)
            {
                return false;
            }
        }
        // 同一个小方块内不能重复
        int startRow = (row / 3)*3;
        int startCol = (col / 3)*3;
        for (int i = startRow; i < startRow + 3; i++)
        {
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (board[i][j] == val)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool traceback(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char k = '1'; k <= '9'; k++)
                    {
                        if (isvalid(board, i, j, k))
                        {
                            board[i][j] = k; // 放置k
                            if (traceback(board))
                                return true;   // 如果找到合适一组立刻返回
                            board[i][j] = '.'; // 回溯，撤销k
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        traceback(board);
    }
};
// @lc code=end
