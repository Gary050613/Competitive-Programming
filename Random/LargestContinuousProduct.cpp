#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, ans=INT_MIN, psa[101]={0}, a;
	psa[0] = 1;
	cin >> N;
	if(N <= 0){
		cout << "Invalid Input!\n";
		return 0;
	}
	for(int i = 1;i<=N;i++){
		cin >> a;
		psa[i] = a * psa[i-1];
		ans = max(ans, a);
	}
	for(int l = 1;l<=N;l++){
		for(int r = l;r<=N;r++){
			if(psa[l-1]==0) continue;
			if(psa[r]/psa[l-1] > ans) ans = psa[r]/psa[l-1];
		}
	}
	cout << ans << endl;
	return 0;
}


