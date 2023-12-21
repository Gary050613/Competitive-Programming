#include <bits/stdc++.h>
using namespace std;

bool judge(string s){
	int len = s.size();
	for(int i = 0;i<len/2;i++) {
		if(s[i] != s[len-i-1]){
			return false;
		}
	}
	return true;
}

string ten2b(int n, int b) {
	string x, dic = "0123456789ABCDEFGHIJ";
	while(n){
		x = dic[n%b] + x;
		n /= b;
	}
	return x;
}

int main(){
	int i,m,b;
	string s;
	cin >> b;
	for(i = 1;i<=300;i++){
		m = i*i;
		s = ten2b(m, b);
		if(judge(s)) {
			cout << ten2b(i,b) << " " << s << endl;
		}
	}
	return 0;
}

