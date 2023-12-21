#include <bits/stdc++.h>
using namespace std;

int main(){
	
	stack<int> s;
	int n, base;
	cin >> n >> base;
	while(n>0){
		s.push(n%base);
		n /= base;
	}
	
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}

	return 0;
}

