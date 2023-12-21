#include <bits/stdc++.h>
using namespace std;

int main(){
	int X, N, P=0, a;
	cin >> X >> N;
	for(int i = 0;i<N;i++){
		cin >> a;
		P += a;
	}
	cout << X*(N+1)-P << endl;
	return 0;
}


