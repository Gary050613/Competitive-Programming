#include <bits/stdc++.h>
using namespace std;

int main(){
	char a1[1001]={}, b1[1001]={};
	int a[1001]={},b[1001]={},c[1001]={},lena,lenb,lenc,sum = 0;
	cin >> a1 >> b1;
	//Get length
	lena = strlen(a1);
	lenb = strlen(b1);
	//Convert to int array
	for(int i = 0;i<lena;i++) {
		a[lena - i - 1] = a1[i] - 48;
	}
	for(int i = 0;i<lenb;i++) {
		b[lenb - i - 1] = b1[i] - 48;
	}
	//Adding
	while(lenc < lena || lenc < lenb) {
		c[lenc] = a[lenc] + b[lenc];
		lenc++;
	}
	for(int i = lenc-1;i>=0;i--) {
		cout << c[i];
	}
	cout << endl;
	
	return 0;
}

