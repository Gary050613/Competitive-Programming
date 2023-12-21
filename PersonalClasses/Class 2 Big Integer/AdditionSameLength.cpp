#include <bits/stdc++.h>
using namespace std;

int main(){
	char a1[1001]={}, b1[1001]={};
	int a[1001]={},b[1001]={},len,sum = 0;
	cin >> a1 >> b1;
	len = strlen(a1);
	for(int i = 0;i<len;i++){
		//ASCII charNumber - 48 = Integer
		a[i] = a1[i] - 48;
		b[i] = b1[i] - 48;
	}
	for(int i = 0;i<len;i++) {
		sum = a[i] + b[i];
		cout << sum;	
	}
	
	return 0;
}

