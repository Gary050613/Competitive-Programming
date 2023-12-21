#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[405][405]={0}, s[405]={0};
int main(){
	int N, ans=0, x=0;
	cin >> N;
	for(int i = 1;i<=N;i++)
		for(int j = 1;j<=N;j++)
			dp[i][j] = 1e18+5;
	for(int i = 1;i<=N;i++){
		cin >> x;
		s[i] = s[i-1]+x;
	}
	for(int i = 1;i<=N;i++){
		dp[i][i] = 0;
	}
	for(int l = 0;l<=N;l++){
		for(int i = 1;i<=N-l+1;i++){
			int j = i+l-1;
			for(int mid = i;mid<=j-1;mid++){
				dp[i][j] = min(dp[i][mid]+dp[mid+1][j]+s[j]-s[i-1], dp[i][j]);
			}
		}
	}
//	for(int i = 1;i<=N;i++){
//		for(int j = 1;j<=N;j++){
//			cout << dp[i][j] << ' ';
//		}
//		cout << endl;
//	}
	cout << dp[1][N] << endl;
	return 0;
}


