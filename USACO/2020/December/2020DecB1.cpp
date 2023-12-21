#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int arr[7];
	for(int i = 0;i<7;i++){
		cin >> arr[i];
	}
	sort(arr, arr+7);
	int sum = arr[6];
	for(int i = 0;i<6;i++){
		for(int j = i+1;j<6;j++){
			for(int k = j+1;k<6;k++){
				if(arr[i] + arr[j] + arr[k] == sum){
					cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
					break;
				}
			}
		}
	}
	
	return 0;
}


