#include <bits/stdc++.h>
using namespace std;

int main(){
	char a1[1001]={}, b1[1001]={};
	int a[1001]={},b[1001]={},c[1001]={},len,i,lenc = 0,x = 0;
	cin >> a1 >> b1;
	len = strlen(a1);
	for(int i = 0;i<len;i++) {
		a[len-i-1] = a1[i] - 48;
		b[len-i-1] = b1[i] - 48;
	}
	while(lenc<len) {
		c[lenc] = a[lenc] + b[lenc] + x;
		x = c[lenc]/10;
		c[lenc] %= 10;
		lenc++;	
	}
	c[lenc] = x;
	if(!x) {
		lenc--;
	}
	for(int i = lenc;i>=0;i--) {
		cout << c[i];
	}


	return 0;
}

