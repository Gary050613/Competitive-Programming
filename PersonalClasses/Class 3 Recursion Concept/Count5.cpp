#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, ans;
	cin >> n;
	if(n%2==0){
		ans = 8 * (int)pow(9,n-1) + 1;
	}else{
		ans = 9 * (int)pow(10,n-1) - 9*9 - 8*9*(n-1) - 1;
	}
	cout << ans;
	

	return 0;
}

