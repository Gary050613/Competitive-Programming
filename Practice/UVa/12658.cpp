#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	char arr[7][41];
	for(int i = 0;i<5;i++){
		for(int j = 0;j<4*n;j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0;i<n;i++){
		if(arr[1][i*4+1]=='*'){
			cout << 1;
		}else if(arr[3][i*4]=='*'){
			cout << 2;
		}else if(arr[3][i*4+2]=='*'){
			cout << 3;
		}
	}
	cout << endl;
	return 0;
}


