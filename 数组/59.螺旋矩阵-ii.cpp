/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int startx, starty;
        startx=0,starty=0;
        int loop=n/2;
        int mid=n/2;
        int count=1;
        int offset=1;
        int i,j;
        while (loop--)
        {
            i=startx;
            j=starty;
            for(j;j<n-offset;j++){
                res[i][j] = count++;
            }
            for(i;i<n-offset;i++){
                res[i][j] = count++;
            }
            for(;j>starty;j--){
                res[i][j] = count++;
            }
            for(;i>startx;i--){
                res[i][j] = count++;
            }
            startx++;
            starty++;
            offset++;
        }
        if(n%2){
            res[mid][mid]=count;
        }
        return res;
    }
};
// @lc code=end

