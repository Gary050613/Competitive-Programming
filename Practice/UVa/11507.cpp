#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	string str, cur;
	while(cin >> T && T){
		T--;
		cur = "+x";
		while(T--){
			cin >> str;
			if(str == "+z"){
				if(cur == "+z") cur = "-x";
				else if(cur == "-z") cur = "+x";
				else if(cur == "+x") cur = "+z";
				else if(cur == "-x") cur = "-z";
			}else if(str == "-z"){
				if(cur == "+z") cur = "+x";
				else if(cur == "-z") cur = "-x";
				else if(cur == "+x") cur = "-z";
				else if(cur == "-x") cur = "+z";
			}else if(str == "+y"){
				if(cur == "+y") cur = "-x";
				else if(cur == "-y") cur = "+x";
				else if(cur == "+x") cur = "+y";
				else if(cur == "-x") cur = "-y";
			}else if(str == "-y"){
				if(cur == "+y") cur = "+x";
				else if(cur == "-y") cur = "-x";
				else if(cur == "+x") cur = "-y";
				else if(cur == "-x") cur = "+y";
			}
		}
		cout << cur << endl;
	}
	return 0;
}


