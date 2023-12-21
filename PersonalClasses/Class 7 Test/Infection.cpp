#include <bits/stdc++.h>
using namespace std;

int main(){
	
	/*
		. . . . #
		. # . @ .
		. # @ . .
		# . . . .
		. . . . .
	*/
	
	int n, days, ans = 0;
	cin >> n;
	char arr[n][n], a;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin >> a;
			if(a == '@'){
				ans++;
			}
			arr[i][j] = a;
		}
	}
	cin >> days;
	for(int i = 2;i<=days;i++){
		for(int j = 0;j<n;j++){
			for(int k = 0;k<n;k++){
				if(arr[j][k] == '@'){
					if(arr[j-1][k] == '.'){
						
					}
				}
			}
		}
	}
	

	return 0;
}


