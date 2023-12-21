#include <bits/stdc++.h>
using namespace std;

int f(int n){
	if(n < 10){
		return n;
	}
	int ans = 0;
	while(n != 0){
		ans += n%10;
		n/=10;
	}
	return f(ans);
}

int main(){
	int a;
	while(cin >> a && a){
		cout << f(a) << endl;
	}
	return 0;
}


