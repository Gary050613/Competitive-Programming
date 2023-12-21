#include <bits/stdc++.h>
using namespace std;

int main(){
	
	bool ans = true;
	char arr[101], stack[101];
	cin >> arr;
	int top = 0;
	for(int i = 0;i<strlen(arr);i++){
		switch(arr[i]){
			case '(':
				stack[top++] = arr[i];
				break;
			case '[':
				stack[top++] = arr[i];
				break;
			case ')':
				if(stack[--top]!='('){
					ans = false;
					i = 101;
				}
				break;
			case ']':
				if(stack[--top]!='['){
					ans = false;
					i = 101;
				}
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

