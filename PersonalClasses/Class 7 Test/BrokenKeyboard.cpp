#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string str;
	stack<char> s;
	string ans = "", temp = "";
	while(cin >> str){
		int len = str.length();
		for(int i = 0;i<len;i++){
			if(str[i] == '['){
				s.push('[');
			}else if(str[i] == ']'){
				s.pop();
			}else{
				if(s.empty()){
					ans = temp + ans;
					temp = "";
					ans = ans + str[i];
				}else{
					temp = temp + str[i];
				}
			}
		}
		ans += "\n";
	}
	cout << ans << endl;

	return 0;
}


