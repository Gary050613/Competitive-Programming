#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, a = 0, ans = 0;
	cin >> n;
	while(n>0){
		ans += n%8 * pow(10,a);
		n /= 8;
		a++;
	}
	cout << ans << endl;

	return 0;
}

