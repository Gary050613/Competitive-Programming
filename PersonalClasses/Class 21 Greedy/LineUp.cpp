#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, r, p[101], ans = 0;
	cin >> n >> r;
	for(int i = 0;i<n;i++){
		cin >> p[i];
	}
	sort(p, p+n);
	for(int i = 0;i<n;i++){
		ans += p[i] * ((n-i+r-1)/r);
//		cout << ans << endl;
	}
	cout << ans << endl;
	
	return 0;
}

/*
4 2
2 5 6 4
*/
