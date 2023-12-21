#include <bits/stdc++.h>
using namespace std;

int main(){

	stack<int> s;
	string arr;
	cin >> arr;
	bool ans = true;
	for(int i = 0;i<arr.length();i++){
		switch(arr[i]){
			case '(':
				s.push(arr[i]);
				break;
			case '[':
				s.push(arr[i]);
				break;
			case ')':
				if(s.top()!='('){
					ans = false;
					i = 101;
				}
				s.pop();
				break;
			case ']':
				if(s.top()!='['){
					ans = false;
					i = 101;
				}
				s.pop();
				break;
		}
	}
	if(ans){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

	return 0;
}

