#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int T;
	cin >> T;
	while(T--){
		ll n, m, a, x, y, ans=0;
		cin >> n >> m >> a;
		y = (a-1) / n;
		x = (a-1) % n;
		ans = x*m+y+1;
		cout << ans << endl;
	}
	return 0;
}


