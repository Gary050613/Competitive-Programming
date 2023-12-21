#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	int dp[55] = {0}, ans = 0;
	for(int i = 0;i<str.length();i++){
		dp[i] = 1;
	}
	for(int i = 1;i<str.length();i++){
		for(int j = 0;j<i;j++){
			if(str[i]>str[j]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	for(int i = 0;i<str.length();i++){
		ans = max(ans, dp[i]);
//		cout << dp[i] << " ";
	}
	cout << 26-ans << endl;
	return 0;
}


