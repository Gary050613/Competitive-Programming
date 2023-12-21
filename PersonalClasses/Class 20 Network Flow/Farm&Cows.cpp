#include <bits/stdc++.h>
using namespace std;
int maxn = 99999;
int main(){
	
	int cows, farms, roads, catf[801] = {0}, a, b, c, ans = maxn;
	int dis[801];
	int u[1451], v[1451], w[1451];
	cin >> cows >> farms >> roads;
	for(int i = 1;i<=cows;i++){
		cin >> a;
		catf[a]++;
	}
	for(int i = 1;i<=roads;i++){
		cin >> u[i] >> v[i] >> w[i];
//		g[u[i]][v[i]] = g[v[i]][u[i]] = w[i];
	}
	for(int k = 1;k<=farms;k++){
		int total = 0;
		for(int i = 1;i<=farms;i++){
			dis[i] = maxn;
		}
		dis[k] = 0;
		for(int i = 1;i<=farms-1;i++){
			for(int j = 1;j<=roads;j++){
				if(dis[v[j]] > dis[u[j]] + w[j]){
					dis[v[j]] = dis[u[j]]+w[j];
				}
				if(dis[u[j]] > dis[v[j]] + w[j]){
					dis[u[j]] = dis[v[j]]+w[j];
				}
			}
		}
		for(int i = 1;i<=farms;i++){
			total+=dis[i]*catf[i];
		}
//		for(int i = 1;i<=farms;i++){
//			cout << dis[i] << " ";
//		}
//		cout << endl;
		ans = min(ans, total);
	}
	cout << ans << endl;
	
	return 0;
}

/*
3 4 5
2
3
4
1 2 1
1 3 5
2 3 7
2 4 3
3 4 5
*/
