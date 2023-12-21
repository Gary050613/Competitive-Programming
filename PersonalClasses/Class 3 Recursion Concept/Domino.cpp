#include <bits/stdc++.h>
using namespace std;

int domino(int n) {
	if(n<=2){
		return n;
	}
	return domino(n-1) + domino(n-2);
}

int main(){
	int n;
	cin >> n;
	cout << domino(n) << endl;
	
	return 0;
}

