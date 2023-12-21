#include <bits/stdc++.h>
using namespace std;
int T; double ans, mp[100]; string input;
int main(){
	mp['C'] = 12.01;
	mp['H'] = 1.008;
	mp['O'] = 16.00;
	mp['N'] = 14.01;
	cin >> T;
	while(T--){
		ans=0;
		cin >> input;
		for(int i = 0;i<input.length();i++){
			char ch = input[i];
			string count="";
			for(int j = i+1;j<input.length();j++){
				if(isdigit(input[j])) count = count + input[j];
				else {
					i=j-1;
					break;
				}
			}
			if(count == "") ans+=mp[ch];
			else ans+=mp[ch]*stoi(count);
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}


