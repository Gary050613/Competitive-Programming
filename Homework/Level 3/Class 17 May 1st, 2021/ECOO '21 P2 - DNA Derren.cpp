#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
string seq, ans[MM]; bool vow[MM]={0}; int cur=0;
int main(){
	cin >> seq;
	for(int i = 0;i<seq.length();i++){
		if(ans[cur]=="") ans[cur].push_back(seq[i]);
		else{
			if(ans[cur][ans[cur].length()-1]=='A'){
				if(seq[i]!='A') ans[cur].push_back(seq[i]);
				else ans[++cur].push_back(seq[i]);
			}else{
				if(seq[i]=='A') ans[cur].push_back(seq[i]);
				else ans[++cur].push_back(seq[i]);
			}
		}
	}
	for(int i = 0;i<=cur;i++){
		cout << ans[i] << " ";
	}
	return 0;
}


