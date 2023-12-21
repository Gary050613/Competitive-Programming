#include <bits/stdc++.h>
using namespace std;
int n,m, f[105][105]={0};
char p[105][105];
int main(){
	int cnt=1;
	while(cin >> n >> m && (n||m)){
		memset(f, 0, sizeof(f));
		if(cnt > 1) cout << endl;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				cin >> p[i][j];
				if(p[i][j]=='*'){
					f[i-1][j-1]++, f[i-1][j]++, f[i-1][j+1]++, f[i][j+1]++, f[i+1][j+1]++, f[i+1][j]++, f[i+1][j-1]++, f[i][j-1]++;
				}
			}
		}
		printf("Field #%d:\n", cnt++);
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				if(p[i][j]=='*') cout << "*";
				else cout << f[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}


