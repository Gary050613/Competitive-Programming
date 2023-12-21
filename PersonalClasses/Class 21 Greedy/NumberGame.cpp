#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, arr[10001], front = 1;
	int sumodd = 0, sumeven = 0;
	cin >> n;
	int back = n*2;
	for(int i = 1;i<=n*2;i++){
		cin >> arr[i];
		if(i % 2 == 0){
			sumeven+=arr[i];
		}else{
			sumodd+=arr[i];
		}
	}
	if(sumodd >= sumeven){
		for(int i = 1;i<=n;i++){
			if(back % 2 == 0){
				cout << arr[front++] << endl;
				if(arr[front] >= arr[back]){
					cout << "L " << arr[front++];
				}else{
					cout << "R " << arr[back--];
				}
			}else{
				cout << arr[back--] << endl;
				if(arr[front] >= arr[back]){
					cout << "L " << arr[front++];
				}else{
					cout << "R " << arr[back--];
				}
			}
			
		}
		cout << sumodd << endl << sumeven;
		
	}else{
		for(int i = 1;i<=n;i++){
			if(front % 2 == 0){
				cout << arr[front++] << endl;
				if(arr[front] >= arr[back]){
					cout << "L " << arr[front++] << endl;
				}else{
					cout << "R " << arr[back--] << endl;
				}
			}else{
				cout << arr[back--] << endl;
				if(arr[front] >= arr[back]){
					cout << "L " << arr[front++] << endl;
				}else{
					cout << "R " << arr[back--] << endl;
				}
			}
		}
		cout << sumeven << endl << sumodd;
		
	}
	
	
	return 0;
}
/*
4
7 9 3 6 4 2 5 3
*/

