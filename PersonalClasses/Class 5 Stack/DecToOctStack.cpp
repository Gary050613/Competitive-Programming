#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, digits[101], top = 0;
	cin >> n;
	while(n>0){
		digits[++top] = n%8;
		n /= 8;
	}
	
	while(top!=0){
		cout << digits[top--];
	}

	return 0;
}

