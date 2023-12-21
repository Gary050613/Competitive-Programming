#include <bits/stdc++.h>
using namespace std;
int convertChar(char ch){
	if(ch >= 65 && ch <= 90){
		return ch-64;
	}
	if(ch >= 97 && ch <= 122){
		return ch-96;
	}
	return 0;
}

string convertStr(string str){
	string ans = "";
	for(int i = 0;i<str.length();i++){
		ans += to_string(convertChar(str[i]));
	}
	return ans;
}

int calcStr(string str){
	int ans = 0;
	for(int i = 0;i<str.length();i++){
		ans += str[i]-48;
	}
	return ans;
}

int calcSum(int n){
	int ans = 0;
	while(n!=0){
		ans += n%10;
		n/=10;
	}
	return ans;
}

int main(){
	string name1, name2;
	int n1, n2;
	while(getline(cin, name1) && getline(cin, name2)){
		n1 = calcStr(convertStr(name1));
		n2 = calcStr(convertStr(name2));
		while(!(n1 < 10)){
			n1 = calcSum(n1);
		}
		while(!(n2 < 10)){
			n2 = calcSum(n2);
		}
		if(n1 < n2){
			printf("%.2f \%\n", ((double)n1/(double)n2)*100);
		}else{
			printf("%.2f \%\n", ((double)n2/(double)n1)*100);
		}
	}
	return 0;
}


