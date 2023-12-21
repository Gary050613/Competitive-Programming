#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, num[101], a;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> num[i];
	}
	for(int i = 0;i<n-1;i++){
		a = i;
		for(int j = i+1;j<n;j++){
			if(num[j] < num[a]){
				a = j;
			}
		}
		if(a != i){
			swap(num[i],num[a]);
		}
	}
	for(int i = 0;i<n;i++){
		cout << num[i] << " ";
	}

	return 0;
}


