#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[5];
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr+3);
	if(arr[1]-arr[0]==arr[2]-arr[1]){
		cout << arr[2]+arr[2]-arr[1] << endl;
	}else if(arr[2]-arr[1] > arr[1]-arr[0]){
		cout << arr[1] + arr[1] - arr[0] << endl;
	}else{
		cout << arr[0] + arr[2] - arr[1] << endl;
	}
	return 0;
}


