#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M, tea[1001], top[1001], K, a, ans = 2000000001;
	cin >> N;
	for(int i = 1;i<=N;i++){
		cin >> tea[i];
	}
	cin >> M;
	for(int i = 1;i<=M;i++){
		cin >> top[i];
	}
	for(int i = 1;i<=N;i++){
		cin >> K;
		while(K--){
			cin >> a;
			ans = min(ans, tea[i]+top[a]);
		}
	}
	cin >> a;
	ans = (a/ans-1)<0 ? 0 : a/ans-1;
	cout << ans << endl;;
	return 0;
}


