#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int V, n, w[31], c[31], s[31], dp[201] = {0};
	cin >> V >> n;
	for(int i = 1;i<=n;i++){
		cin >> w[i] >> c[i] >> s[i];
	}
	for(int i = 1;i<=n;i++){
		if(s[i] == 0){
			for(int v = w[i];v<=V;v++){
				dp[v] = max(dp[v], dp[v-w[i]]+c[i]);
			}
		}else{
			for(int v = V;v>=w[i];v--){
				for(int k = 0;k<=s[i];k++){
					if(k*w[i]<=v){
						dp[v] = max(dp[v],dp[v-k*w[i]]+k*c[i]);
					}
				}
			}
		}
	}
//	for(int i = 1; i <= n; i++){
//		if(s[i] == 0){
//			for(int j = w[i]; j <= V; j++){
//				dp[j] = max(dp[j],dp[j-w[i]]+c[i]);
//			}
//		}
//		else{
//			for(int j = 1; j <= s[i]; j++){
//				for(int k = V; k >= w[i];k--){
//					dp[k] = max(dp[k],dp[k-w[i]]+c[i]);
//				}
//			}
//		}
//	}
	cout << dp[V] << "\n";
	
	return 0;
}


