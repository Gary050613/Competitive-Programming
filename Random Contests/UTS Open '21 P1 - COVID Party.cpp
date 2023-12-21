#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, c = 0, ans = 0;
	cin >> n;
	while(c < n){
		c+=(ans/2)*2+1;
		ans++;
	}
	cout << ans-1 << endl;
	return 0;
}


