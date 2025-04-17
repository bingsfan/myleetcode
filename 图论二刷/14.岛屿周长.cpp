#include <vector>
#include <iostream>
using namespace std;
/* 
	计算总共有多少个小块，cnt，那总共有cnt*4条边，然后检查当前块的上面和左面是否有重复
	用cover记录重复边，最最后的周长就等于cnt*4-2*cover
*/
void daoyuzhouchang(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> graph(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>graph[i][j];
		}
	}
	int cnt=0;
	int cover=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(graph[i][j]==1){
				cnt++;
				if(i-1>=0&&graph[i-1][j]==1) cover++;
				if(j-1>=0&&graph[i][j-1]==1) cover++;
			}
		}
	}
	int perimeter = cnt*4-cover*2;
	cout<<perimeter<<endl;
}
int main(int argc, char *argv[]) {
    daoyuzhouchang();
    return 0;
}