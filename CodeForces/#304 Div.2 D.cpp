//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//ll dp[5000001]={0};
//
//ll find(ll x){
//	if(x == 1){
//		return 0;
//	}
//	if(dp[x] != 0){
//		return dp[x];
//	}
//	for(int i = 2;i<=(ll)sqrt(x);i++){
//		if(x%i==0){
//			dp[x] = find(x/i) + find(i);
//			break;
//		}
//		if(i == (ll)sqrt(x)){
//			dp[x] = 1;
//		}
//	}
//	return dp[x];
//}
//
//int main(){
//	ll n, a, b, ans=0;
//	scanf("%lld", &n);
//	dp[2] = 1;
//	dp[3] = 1;
//	while(n--){
//		ans = 0;
//		scanf("%lld%lld", &a, &b);
//		for(int i = b+1;i<=a;i++){
//			ans += find(i);
//		}
//		printf("%lld\n", ans);
//	}
//}
#include <bits/stdc++.h>
using namespace std;

int cur[5000005], factors[5000005];

int main() {
	for (int i = 1; i <= 5000000; ++i) cur[i] = i;
	for (int i = 1; i <= 5000000; ++i) if (cur[i] > 1)
		for (int j = i; j <= 5000000; j += i)
			while (cur[j]%i == 0) {
				cur[j] /= i;
				++factors[j];
			}
	for (int i = 1; i <= 5000000; ++i) factors[i] += factors[i-1];
	int T; scanf("%d",&T);
	for (int i = 0; i < T; ++i) {
		int a,b; scanf("%d%d",&a,&b);
		printf("%d\n",factors[a]-factors[b]);
	}
}

