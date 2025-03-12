#include <iostream>
#include <vector>
using namespace std;
/* 
题目描述
给定一个由 1（陆地）和 0（水）组成的矩阵，岛屿是被水包围，并且通过水平方向或垂直方向上相邻的陆地连接而成的。
你可以假设矩阵外均被水包围。在矩阵中恰好拥有一个岛屿，假设组成岛屿的陆地边长都为 1，
请计算岛屿的周长。岛屿内部没有水域。
输入描述
第一行包含两个整数 N, M，表示矩阵的行数和列数。之后 N 行，每行包含 M 个数字，数字为 1 或者 0，表示岛屿的单元格。
输出描述
输出一个整数，表示岛屿的周长。
输入示例
5 5
0 0 0 0 0 
0 1 0 1 0
0 1 1 1 0
0 1 1 1 0
0 0 0 0 0
输出示例
14
*/
int main() {
    int n,m;
    cin>>n>>m;
    int sum=0;
    int cover=0;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                sum++;
                if(i-1>=0&&grid[i-1][j]==1){
                    cover++;
                }
                if(j-1>=0&&grid[i][j-1]==1){
                    cover++;
                }
            }
        }
    }
    cout<<sum*4-cover*2<<endl;
}                                   