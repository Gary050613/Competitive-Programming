#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fib[100000001];
int main(){
	
	ll M, ans;
	scanf("%lld", &M);
	fib[0] = 0;
	fib[1] = 1;
	for(int i = 2;i<=M*M+1;i++){
		fib[i] = (fib[i-2] + fib[i-1])%M;
//		printf("%lld\n", fib[i]);
		if(fib[i-1]%M == 0 && fib[i]%M == 1){
			ans = i-1;
			break;
		}
	}
	printf("%lld", ans);
	
	return 0;
}


