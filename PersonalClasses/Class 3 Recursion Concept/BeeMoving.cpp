#include <bits/stdc++.h>
using namespace std;

int bee(int n){
	if(n <= 3){
		return n;
	}
	return bee(n-1) + bee(n-2);
}

int main(){

	int m, n;
	cin >> m >> n;
	cout << bee(n-m);

	return 0;
}

