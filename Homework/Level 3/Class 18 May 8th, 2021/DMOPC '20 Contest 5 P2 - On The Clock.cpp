#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
int main(){
	cin >> n >> m;
	cout << n+m-gcd(n,m) << endl;
	for(int i=1;i<=n;i++){
		ll left = (i-1)*m/n + 1, right = (i*m + n - 1) / n;
		for(ll j = left; j<=right;j++)
			cout << i << " " << j << endl;
	}
	return 0;
}


