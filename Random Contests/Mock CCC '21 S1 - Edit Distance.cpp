#include <bits/stdc++.h>
using namespace std;
int s = 0;
string alphabet, str;
string ans[100001];
int main(){
	
	cin >> alphabet >> str;
	int len = alphabet.length();
	for(int i = 0;i<str.length();i++){
		ans[s++] = str.substr(0,i) + str.substr(i+1, str.length()-i-1);
	}
	for(int i = 0;i<len;i++){
		for(int j = 0;j<str.length();j++){
			ans[s++] = str.substr(0,j) + alphabet[i] + str.substr(j+1, str.length()-j-1);
			ans[s++] = str.substr(0,j) + alphabet[i] + str.substr(j, str.length()-j);
		}
		ans[s++] = str + alphabet[i];
	}
	sort(ans, ans+s);
	string temp = "";
	for(int i = 0;i<s;i++){
		if(temp.compare(ans[i]) == 0 || str.compare(ans[i]) == 0){
			continue;
		}
		temp = ans[i];
		cout << ans[i] << endl;
	}
	
	return 0;
}


