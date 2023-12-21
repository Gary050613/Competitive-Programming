#include <bits/stdc++.h>
using namespace std;

int tree(int n){
	if(n<=2){
		return n;
	}
	return tree(n-1) + n;
}

int main(){

	int n;
	cin >> n;
	cout << tree(n);

	return 0;
}

