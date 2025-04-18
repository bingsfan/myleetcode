#include <bits/stdc++.h>
using namespace std;
void floyd() {
	int n, m, s, t, k;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 10005));
	while(m--) {
		cin >> s >> t >> k;
		graph[s][t] = k;
		graph[t][s] = k;
	}
	// 开始floyd
	for(int p = 1; p <= n; p++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][p] + graph[p][j]);
			}
		}
	}
	int times, start, end;
    cin>>times;
	while(times--) {
		cin >> start >> end;
		if(graph[start][end] == 10005) {
			cout << -1 << endl;
		} else {
			cout << graph[start][end] << endl;
		}
	}
}
int main(int argc, char *argv[]) {
    floyd();
    return 0;
}