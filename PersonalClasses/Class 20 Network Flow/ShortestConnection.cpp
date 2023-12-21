#include <bits/stdc++.h>
using namespace std;
int n, m, start, endp, a, b;
double maxn = 999.00;
double g[101][101] = {0};
double dis[101];

struct point{
	int x, y;
} p[101];

//void solve(){
//	int visited[101] = {0};
//	
//	dis[start] = 0;
//	visited[start] = 1;
//	for(int i = 1;i<=n;i++){
//		dis[i] = g[start][i];
//	}
//	for(int i = 1;i<=n-1;i++){
//		int min = maxn, u;
//		for(int j = 1;j<=n;j++){
//			if(visited[j] == 0 && dis[j] < min){
//				min = dis[j];
//				u = j;
//			}
//		}
//		visited[u] = 1;
//		for(int v = 1;v<=n;v++){
//			if(g[u][v] != 0){
//				if(dis[v] > dis[u] + g[u][v]){
//					dis[v] = dis[u] + g[u][v];
//				}
//			}
//		}
//	}
//}

int main(){
	

	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> p[i].x >> p[i].y;
	}
	cin >> m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			g[i][j] = maxn;
		}
	}
	for(int i = 1;i<=m;i++){
		cin >> a >> b;
		g[a][b] = g[b][a] = sqrt(pow(abs(p[b].x-p[a].x),2) + pow(abs(p[b].y-p[a].y),2));
	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			cout << g[i][j] << " ";
//		}
//		cout << endl;
//	}
	cin >> start >> endp;
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(g[i][j] > g[i][k] + g[k][j]){
					g[i][j] = g[i][k] + g[k][j];
				}
			}
		}
	}
	printf("%.2f",g[start][endp]);
	
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

