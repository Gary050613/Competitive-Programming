#include <bits/stdc++.h>
using namespace std;

int f[1001][1001];
int a[1001][1001];

int main(){
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=i;j++) {
			cin >> a[i][j];
		}
	}
	f[1][1] = a[1][1];
	for(int i = 2;i<=n;i++) {
		for(int j = 1;j<=i;j++) {
			f[i][j] = a[i][j] + max(f[i-1][j-1],f[i-1][j]);
		}
 	}
 	int num = INT_MIN;
 	for(int i = 1;i<=n;i++) {
 		num = max(num, f[n][i]);
	}
	cout << num << endl;
	return 0;
}

