#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, ans=0;
	cin >> n;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	for(int i = 0;i<n-1;i++){
		for(int j = i+1;j<n;j++){
			if(arr[i] > arr[j]){
				cout << arr[i] << " " << arr[j] << endl;
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}


