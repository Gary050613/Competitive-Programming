#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, ans = 1;
	cin >> n;
	for(int i = 0;i<n;i++){
		ans = ans*2 +1;
	}
	cout << ans;
	return 0;
}

