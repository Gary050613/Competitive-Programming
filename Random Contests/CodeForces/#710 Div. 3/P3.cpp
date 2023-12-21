#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		string a, b;
		cin >> a >> b;
		int ans=0, length = min(a.length(),b.length()), longest = 0;
		for(int i = length;i>=0;i--){
			for(int j = 0;j+i<=a.length();j++){
				for(int k = 0;k+i<=b.length();k++){
					if(a.substr(j,i)==b.substr(k,i)){
						longest = i;
						i = -1, j = a.length()+1, k = b.length()+1;
						break;
					}
				}
			}
		}
		cout << a.length()+b.length()-longest-longest << endl;
	}
	return 0;
}


