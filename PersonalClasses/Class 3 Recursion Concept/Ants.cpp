#include <bits/stdc++.h>
using namespace std;

int ants(int x, int y, int n){
	if(n<=x+1) {
		return 1;
	}
	return (ants(x, y, n-x-2) * y) + ants(x, y, n-1);
}


int main(){

	int x, y, z;
	cin >> x >> y >> z;
	cout << ants(x, y, z);

	return 0;
}

