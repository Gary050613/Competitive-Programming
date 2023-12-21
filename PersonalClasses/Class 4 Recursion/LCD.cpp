#include <bits/stdc++.h>
using namespace std;

int LCD(int a, int b){
	if(a==0){
		return b;
	}else if(b==0){
		return a;
	}else{
		if(a >= b){
			return LCD(a%b, b);
		}else{
			return LCD(a, b%a);
		}
	}
}

int main(){

	int a, b;
	cin >> a >> b;
	int c = LCD(a, b);
	cout << c;

	return 0;
}

