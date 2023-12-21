#include <bits/stdc++.h>
using namespace std;
const int MM = 303;
int dp[MM][MM], n; string s;
bool get(char a, char b){
	if((a == '(' && b == ')') || (a=='[' && b==']')) return true;
	return false;
}

int fun(int L, int R){
	if(L >= R) return 0;
	if(dp[L][R] != -1) return dp[L][R];
	for(int m = L+1;m <= R;m++){
		if(get(s[L], s[m])) fun(L+1, m-1);
	}
}

int main(){
	memset(dp, -1, sizeof(dp));
	return 0;
}


