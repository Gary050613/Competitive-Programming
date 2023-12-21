/*
Good Question
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string str;
	cin >> n;
	while(n--){
		cin >> str;
		// prev[height]=i stores the location i of the latest occurance of '\' on level height
		int prev[20005]={0}, height = 10001, ans = 0;
		for(int i = 0;i<str.length();i++){
			if(str[i]=='\\'){
				// i+1 because the string starts at index 0 but requires to be positive on line 20
				prev[height--] = i+1;
			// When the program finds an occurance of '/' AND there is a previous '\' on the same level height
			}else if(str[i]=='/' && prev[++height]){
				// Computes the distance from the previous '\' and the current '/'
				ans += i-prev[height]+1;
				// Makes it 0 to not trigger line 20 again
				prev[height] = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
