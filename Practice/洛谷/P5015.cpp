#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string str;
	getline(cin, str);
	int ans = str.length();
	for(int i = 0;i<str.length();i++){
		if(str[i]==' '){
			ans--;
		}
	}
	printf("%d", ans);
	
	return 0;
}


