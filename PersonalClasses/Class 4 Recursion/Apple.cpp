#include <bits/stdc++.h>
using namespace std;

int apple(int a,int b){
	if(a == 0 || b == 1){
		return 1;
	}
	if(b>a){
		return apple(a, a);
	}
	return apple(a-b, b) + apple(a, b-1);
}

int main(){

	int n;
	int a, b;
	cin >> n;
	while(n--){
		cin >> a >> b;
		cout << apple(a, b) << endl;
	}

	return 0;
}

