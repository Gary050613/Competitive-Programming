#include <bits/stdc++.h>
using namespace std;
int n, m, start, endp, a, b;
double maxn = 999.00;
double g[101][101] = {0};
double dis[101];
int u[101], v[101];
double w[101];

struct point{
	int x, y;
} p[101];

int main(){
	

	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> p[i].x >> p[i].y;
	}
	cin >> m;
	for(int i = 1;i<=n;i++){
		dis[i] = maxn;
	}
	for(int i = 1;i<=m;i++){
		cin >> u[i] >> v[i];
		w[i] = sqrt(pow(abs(p[v[i]].x-p[u[i]].x),2) + pow(abs(p[v[i]].y-p[u[i]].y),2));
	}
	cin >> start >> endp;
	dis[start] = 0;
	for(int j = 1;j<=n-1;j++){
		for(int i = 1;i<=m;i++){
			if(dis[v[i]] > dis[u[i]] + w[i]){
				dis[v[i]] = dis[u[i]] + w[i];
			}
		}
	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			cout << g[i][j] << " ";
//		}
//		cout << endl;
//	}
	printf("%.2f",dis[endp]);
	
	return 0;
}
/*
5
0 0
2 0
2 2
0 2
3 1
5
1 2
1 3
1 4
2 5
3 5
1 5
*/

