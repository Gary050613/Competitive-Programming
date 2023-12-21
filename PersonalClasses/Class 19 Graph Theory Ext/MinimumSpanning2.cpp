#include <bits/stdc++.h>
using namespace std;
int g[101][101], father[101];
struct edge{
	int w, x, y;
} edges[101];

bool compare(edge e1, edge e2){
	if(e1.w < e2.w){
		return true;
	}else{
		return false;
	}
}

int getFather(int i){
	if(father[i] != i){
		return getFather(father[i]);
	}
	return father[i];
}

void unionn(int x, int y){
	father[getFather(y)] = getFather(x);
}

int main(){
	
	int n, cnt = 0;
	cin >> n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin >> g[i][j];
			if(g[i][j] != 0 && j>i){
				edges[cnt].x = i;
				edges[cnt].y = j;
				edges[cnt++].w = g[i][j];
			}
		}
	}
	int ans = 0;
	sort(edges, edges+cnt, compare);
	for(int i = 0;i<n;i++){
		father[i] = i;
	}
	for(int i = 0;i<cnt;i++){
		if(getFather(edges[i].x) != getFather(edges[i].y)){
			unionn(edges[i].x, edges[i].y);
			ans += edges[i].w;
		}
	}
	cout << ans << endl;
	return 0;
}


