#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int ans = n;
	for(int i = n-1;i>=1;i--){
		ans = (ans+i) * 2;
	}
	cout << ans;
	
	return 0;
}

