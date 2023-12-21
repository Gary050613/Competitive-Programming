#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h[10003]={0}, w[10001]={0};

int main(){
	
	int N;
	ll ans = 0;
	scanf("%d", &N);
	for(int i = 1;i<=N+1;i++){
		scanf("%lld", &h[i]);
	}
	for(int i = 1;i<=N;i++){
		scanf("%lld", &w[i]);
	}
	for(int i = 1;i<=N;i++){
		ans += (h[i]+h[i+1])*w[i];
	}
	if(ans % 2 == 0){
		printf("%lld\n", ans/2);
	}else{
		printf("%lld.5\n", ans/2);
	}
	
	
	return 0;
}


