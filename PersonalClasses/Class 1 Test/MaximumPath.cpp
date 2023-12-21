#include <bits/stdc++.h>
using namespace std;

int f[1001][1001];
int a[1001][1001];

int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<=i;j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0;i<n;i++) {
		f[n][i] = a[n][i];
	}
	for(int i = n-1;i>=0;i--) {
		for(int j = 0;j<=i;j++) {
			f[i][j] = a[i][j] + max(f[i+1][j], f[i+1][j+1]);
		}
	}
	cout << f[0][0];
	return 0;
}




