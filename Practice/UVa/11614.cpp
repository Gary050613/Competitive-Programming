#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	int n;
	ll a;
	scanf("%d", &n);
	while(n--){
		scanf("%lld", &a);
		printf("%lld\n", ((ll)sqrt(8 * a + 1)-1)/2);
	}
	
	return 0;
}


