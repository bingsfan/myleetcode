/*
58. 区间和（第九期模拟笔试）
题目描述
给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。
输入描述
第一行输入为整数数组 Array 的长度 n，接下来 n
行，每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间下标：a，b （b >
= a），直至文件结束。 输出描述 输出每个指定区间内元素的总和。 输入示例
5
1
2
3
4
5
0 1
1 3
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k, a, b;
    cin >> n;
    vector<int> num(n);
    vector<int> presum(n);
    int psum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        psum += num[i];
        presum[i] = psum;
    }
    while (cin >> a >> b)
    {
        int sum;
        if (a == 0)
        {
            sum = presum[b];
        }
        else
        {
            sum = presum[b] - presum[a - 1];
        }
        cout << sum << endl;
    }
    return 0;
}
