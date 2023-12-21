#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	for(int i = 0;i<str.length();i++){
		if(str.substr(i, 3)=="RBL"||str.substr(i, 3)=="RLB"||str.substr(i, 3)=="BRL"||
		   str.substr(i, 3)=="BLR"||str.substr(i, 3)=="LRB"||str.substr(i, 3)=="LBR"){
		   	cout << "C";
		   	i+=2;
		}else if(str[i]=='R'){
			cout << "S";
		}else if(str[i]=='B'){
			cout << "K";
		}else if(str[i]=='L'){
			cout << "H";
		}
	}
	cout << endl;
	return 0;
}


