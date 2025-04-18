#include <bits/stdc++.h>
using namespace std;
int grid[1001][1001];
int dir[8][2] = { -2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2 };
int b1, b2;
struct Knight {
	int x, y, f, g, h;
};
struct mycompare {
	bool operator()(const Knight &a, const Knight &b) {
		return a.f > b.f;//这里要用小顶堆
	}
};
int Heuristic(int x1, int y1) {	   // 欧拉距离
	return (x1 - b1) * (x1 - b1) + (y1 - b2) * (y1 - b2);
}
priority_queue<Knight, vector<Knight>, mycompare> pq;
void astar(const Knight &k) {
	Knight cur, next;
	pq.push(k);
	while(!pq.empty()) {
		cur = pq.top();
		pq.pop();
		if(cur.x == b1 && cur.y == b2)
			break;
		for(int i = 0; i < 8; i++) {
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			if(next.x < 1 || next.x > 1000 || next.y < 1 || next.y > 1000)
				continue;
			if(grid[next.x][next.y]==0) {
				grid[next.x][next.y] = grid[cur.x][cur.y] + 1;
				// 开始计算F
				next.g = cur.g + 5;
				next.h = Heuristic(next.x,next.y);
				next.f = next.g + next.h;
				pq.push(next);
			}
		}
	}
}

void solution() {
	int n, a1, a2;
    cin>>n;
	while(n--) {
		cin >> a1 >> a2 >> b1 >> b2;
        memset(grid,0,sizeof(grid));
		Knight knight;
		knight.x = a1, knight.y = a2;
		knight.g = 0, knight.h = Heuristic(a1, a2);
		knight.f = knight.g + knight.h;
		astar(knight);
        while (!pq.empty())
        {
            pq.pop();
        }
        cout<<grid[b1][b2]<<endl;
	}
    return;
}
int main(int argc, char *argv[]) {
    solution();
    return 0;
}