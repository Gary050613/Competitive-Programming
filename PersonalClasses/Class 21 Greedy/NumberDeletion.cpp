#include <bits/stdc++.h>
using namespace std;

int main(){
	
	char n[241];
	int s;
	cin >> n >> s;
	int len = strlen(n);
	for(int i = 0;i<s;i++){
		for(int j = 0;j<len-i-1;j++){
			if(n[j] >= n[j+1]){
				for(int k = j;k<len-i-1;k++){
					n[k] = n[k+1];
				}
				break;
			}
		}
	}
	for(int i = 0;i<len-s;i++){
		cout << n[i];
	}
	return 0;
}


