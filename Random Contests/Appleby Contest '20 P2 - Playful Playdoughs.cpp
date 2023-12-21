#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[100001]={0};

int main(){
	
	ll N, Q, a, b;
	scanf("%lld %lld", &N, &Q);
	memset(p, 0, sizeof(p));
	while(N--){
		scanf("%lld", &a);
		p[a]++;
	}
	while(Q--){
		scanf("%lld %lld", &a, &b);
		if(a == 1){
			p[b/2] += p[b];
			p[(b+1)/2] += p[b];
			p[b] = 0;
		}else{
			printf("%lld\n", p[b]);
		}
	}
	
	return 0;
}


