#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, n, a;
	string str;
	cin >> T;
	while(T--){
		cin >> n;
		int arr[101], p=0;
		for(int i = 1;i<=n;i++){
			cin >> str;
			if(str == "LEFT"){
				arr[i] = -1;
			}else if(str == "RIGHT"){
				arr[i] = 1;
			}else{
				cin >> str >> a;
				arr[i] = arr[a];
			}
			p += arr[i];
		}
		cout << p << endl;
	}
	return 0;
}


