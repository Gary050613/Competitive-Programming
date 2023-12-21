#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	int arr[101][101];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<=i;j++){
			if(j == 0 || i == j){
				arr[i][j] = 1;
			}else{
				arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

