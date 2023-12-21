#include <bits/stdc++.h>
using namespace std;
int psa[1000005]={0}, arr[1000005]={0};
int main(){
	int N, K, ans=-1;
	cin >> N >> K;
	for(int i = 1;i<=N;i++){
		cin >> psa[i];
		psa[i] = psa[i-1]+psa[i];
		psa[i] %= K;
		if(!arr[psa[i]]) arr[psa[i]] = i;
	}
//	arr[0] = 0;
	for(int r = N;r>=0;r--){
		if(psa[r]==0) ans=max(ans, r);
		else if(arr[psa[r]]) ans=max(ans, r - arr[psa[r]]);
	}
//	for(int i = 0;i<=N;i++){
//		cout << arr[i] << " ";
//	}
	cout << ans << endl;
	return 0;
}


