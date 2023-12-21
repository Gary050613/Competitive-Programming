#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, n, a, ans, prev=0;
	cin >> T;
	while(T--){
		ans = INT_MIN;
		cin >> n;
		cin >> prev;
		n--;
		while(n--){
			cin >> a;
			ans = max(ans, prev-a);
			prev = max(prev, a);
		}
		cout << ans << endl;
	}
	return 0;
}


