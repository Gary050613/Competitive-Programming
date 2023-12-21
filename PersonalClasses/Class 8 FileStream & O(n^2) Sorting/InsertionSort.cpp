#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, num[101] = {INT_MAX}, a, index = 0;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a;
		index = 0;
		while(a > num[index]){
			index++;
		}
		for(int j = i;j>=index;j--){
			num[j+1] = num[j];
		}
		num[index] = a;
	}
	for(int i = 0;i<n;i++){
		cout << num[i] << " ";
	}
	

	return 0;
}


