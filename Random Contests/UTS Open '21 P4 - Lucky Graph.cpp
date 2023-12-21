#include <bits/stdc++.h>
using namespace std;
int n, m, u[200001], v[200001], c[200001] = {0}, removed[200001] = {0}, ans = 0, r = 0;
vector<int> g;
int main(){
	
	cin >> n >> m;
	int a, b;
	for(int i = 1;i<=m;i++){
		cin >> a >> b;
		u[i] = a, v[i] = b;
//		g[a].push_back(b);
//		g[b].push_back(a);
		c[a]++;
		c[b]++;
	}
	for(int i = 1;i<=m;i++){
		if(c[u[i]]%2==0 && c[v[i]]%2==0 && removed[i] == 0){
			removed[i] = 1;
			g.push_back(i);
			c[u[i]]--;
			c[v[i]]--;
			r++;
		}
	}
	for(int i = 1;i<=n;i++){
		if(c[i]%2==1){
			ans++;
		}
	}
	cout << ans << "\n" << r << "\n";
	for(int i = 0;i<r;i++){
		cout << g[i] << " ";
	}
	
	return 0;
}


