#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, len, count = 0;
	char m1[1001]={}, flip1[1001]={};
	int m[1001]={}, flip[1001]={}, sum[1001]={}, x = 0;
	cin >> n >> m1;
	len = strlen(m1);
	while(count <= 30) {
		for(int i = 0;i<len;i++) {
			flip1[len-i-1] = m1[i];
		}
		for(int i = 0;i<len;i++) {
			if(m1[i] != flip1[i]) {
				break;
			}
			if(i == len-1) {
				cout << count << endl;
				goto here;
			}
		}
		for(int i = 0;i<len;i++) {
			if(m[i] >= 65) {
				m[i] = m1[i] - 55;
			}else{
				m[i] = m1[i] - 48;
			}
			if(flip[i] >= 65) {
				flip[i] = flip1[i] - 55;
			}else{
				flip[i] = flip1[i] - 48;
			}
		}
		for(int i = 0;i<len+1;i++) {
			sum[i] = m[i] + flip[i] + x;
			x = sum[i]/n;
			sum[i] %= n;
		}
		if(sum[len] != 0) {
			len++;
		}
		for(int i = 0;i<len;i++) {
			if(sum[i] > 9) {
				m1[i] = sum[i] + 55;
			}else{
				m1[i] = sum[i] + 48;
			}
		}
		count++;
	}
	if(count > 30) {
		cout << "Impossible!";
	}
	here: cout << endl;



	return 0;
}

