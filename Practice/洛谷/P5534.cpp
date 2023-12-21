#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	
	ll a, b, n;
	scanf("%lld %lld %lld", &a, &b, &n);
	printf("%lld\n", (a + (a + (n-1) * (b-a))) * n / 2);
	
	return 0;
}


