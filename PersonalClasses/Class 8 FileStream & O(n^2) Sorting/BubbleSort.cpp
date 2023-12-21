#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, num[101];
	bool sorted = true;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> num[i];
	}
	for(int i = 0;i<n;i++){
		sorted = true;
		for(int j = 0;j<n-i-1;j++){
			if(num[j] > num[j+1]){
				swap(num[j],num[j+1]);
				sorted = false;
			}
			if(j == n-i-2 && sorted){
				break;
			}
		}
	}
	for(int i = 0;i<n;i++){
		cout << num[i] << " ";
	}

	return 0;
}


