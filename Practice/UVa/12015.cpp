#include <bits/stdc++.h>
using namespace std;

int main(){
	string arr[11];
	int rel[11];
	int T, cnt=1;
	cin >> T;
	while(T--){
		int n=0;
		for(int i = 1;i<=10;i++){
			cin >> arr[i] >> rel[i];
			if(rel[i]>n){
				n = rel[i];
			}
		}
		printf("Case #%d:\n", cnt++);
		for(int i = 1;i<=10;i++){
			if(rel[i] == n){
				cout << arr[i] << endl;
			}
		}
	}
	return 0;
}


