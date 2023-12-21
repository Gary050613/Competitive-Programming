#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int T, N, dp[MM]={0}; string str;
int main(){
	cin >> T;
	for(int cnt = 1;cnt<=T;cnt++){
		cin >> N >> str;
		dp[0] = 1;
		for(int i = 1;i<(int)str.length();i++){
			if(str[i] > str[i-1]) dp[i] = dp[i-1]+1;
			else dp[i] = 1;
		}
		printf("Case #%d: ", cnt);
		cout << dp[0];
		for(int i = 1;i<str.length();i++){
			cout << " " << dp[i];
		}
		cout << endl;
	}
	return 0;
}


