#include <bits/stdc++.h>
using namespace std;

int age(int n){
	if(n==1){
		return 10;
	}
	return 2 + age(n-1);
}

int main(){

	int n;
	cin >> n;
	cout << age(n);

	return 0;
}

