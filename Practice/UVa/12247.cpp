#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[10];
	while(cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] && (arr[0]||arr[1]||arr[2]||arr[3]||arr[4])){
		sort(arr, arr+3);
		sort(arr+3,arr+5);
		int X, Y;
		if(arr[3]>arr[2]) X = 3;
		else if(arr[3]>arr[1]) X = 2;
		else if(arr[3]>arr[0]) X = 1;
		else X = 0;
		if(arr[4]>arr[2]) Y = 3;
		else if(arr[4]>arr[1]) Y = 2;
		else if(arr[4]>arr[0]) Y = 1;
		else Y = 0;
		if((X == 0 && Y == 3)||(X == 1 && Y == 3)){ // 0 3 3 || 1 3 3
			int ans = -1;
			for(int i = arr[2]+1;i<=52;i++){
				if(arr[3]==i||arr[4]==i){
					continue;
				}else{
					ans = i;
					break;
				}
			}
			cout << ans << endl;
		}else if((X == 2 && Y == 2)||(X == 2 && Y == 3)){ // 2 2 2 || 2 3 2
			int ans = -1;
			for(int i = arr[1]+1;i<=52;i++){
				if(arr[2]==i||arr[3]==i||arr[4]==i){
					continue;
				}else{
					ans = i;
					break;
				}
			}
			cout << ans << endl;
		}else if(X == 3 && Y == 3){ // 3 3 0
			int ans = -1;
			for(int i = 1;i<=52;i++){
				if(arr[0]==i||arr[1]==i||arr[2]==i||arr[3]==i||arr[4]==i){
					continue;
				}else{
					ans = i;
					break;
				}
			}
			cout << ans << endl;
		}else{
			cout << -1 << endl;
		}
	}
	return 0;
}


