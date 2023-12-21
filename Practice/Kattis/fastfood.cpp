#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, n, m, k, arr[31]={0}, ans=0, p[11][31];
	cin >> T;
	while(T--){
		cin >> n >> m;
		memset(arr, 0, sizeof(arr));
		memset(p, 0, sizeof(p));
		ans=0;
		for(int i = 1;i<=n;i++){
			cin >> p[i][0];
			for(int j = 1;j<=p[i][0];j++){
				cin >> p[i][j];
			}
			cin >> p[i][p[i][0]+1];
		}
		for(int i = 1;i<=m;i++){
			cin >> arr[i];
		}
		for(int i = 1;i<=n;i++){
			int times = 101;
			for(int j = 1;j<=p[i][0];j++){
				times = min(times, arr[p[i][j]]);
			}
			ans+=times*p[i][p[i][0]+1];
		}
		cout << ans << endl;
	}
	return 0;
}


