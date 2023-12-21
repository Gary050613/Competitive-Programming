#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	bool flag=0;
	for(int i = 0;i<str.length()-1;i++){
		if(str[i]=='s' && str[i+1]=='s'){
			flag = 1;
			break;
		}
	}
	if(flag){
		cout << "hiss\n";
	}else{
		cout << "no hiss\n";
	}
	return 0;
}


