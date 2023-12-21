#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	
	ll n;
	scanf("%lld", &n);
	while(n!=1){
		printf("%lld ", n);
		if(n%2==0){
			n/=2;
		}else{
			n = n*3+1;
		}
	}
	printf("%lld\n", 1);
	
	return 0;
}


