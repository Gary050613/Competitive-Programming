#include <bits/stdc++.h>
using namespace std;

int main(){
	int C;
	string S, T;
	cin >> C;
	for(int cnt = 1;cnt<=C;cnt++){
		cin >> S >> T;
		int ZtoO=0,OtoZ=0,Qto1=0,Qto0=0, ans=0, swaps=0;
		for(int i = 0;i<S.length();i++){
			if(S[i]=='0'&&T[i]=='1') ZtoO++;
			if(S[i]=='1'&&T[i]=='0') OtoZ++;
			if(S[i]=='?'&&T[i]=='1') Qto1++;
			if(S[i]=='?'&&T[i]=='0') Qto0++;
		}
		ans=min(ZtoO,OtoZ);
		ZtoO-=ans, OtoZ-=ans;
		if(ZtoO) ans+=ZtoO+Qto1+Qto0;
		else{
			if(Qto1<OtoZ) ans=-1;
			else{
				ans+=OtoZ;
				ans+=Qto1+Qto0;
			}
		}
		printf("Case %d: %d\n", cnt, ans);
	}
	return 0;
}


