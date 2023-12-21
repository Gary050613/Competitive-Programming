#include <bits/stdc++.h>
using namespace std;
int n, dp[2001];
string s;
unordered_set<string> st;
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s;
		st.insert(s);
	}
	string str;
	for(int a=0;a<10;a++){
		memset(dp, 0x3f, sizeof(dp));
		cin >> str;
		dp[str.length()]=0;
		for(int i = str.length()-1;i>=0;i--){
			for(int j = i+1;j<=str.length();j++){
				if(st.count(str.substr(i, j-i))) dp[i] = min(dp[i], dp[j]+1);
			}
		}
		cout << dp[0]-1 << endl;
	}
	return 0;
}


