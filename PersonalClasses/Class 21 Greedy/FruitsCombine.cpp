#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, fruits[10001], sum = 0;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> fruits[i];
	}
	sort(fruits, fruits+n);
	for(int i = 0;i<n-1;i++){
		fruits[i+1] += fruits[i];
//		for(int i = 0;i<n;i++){
//			cout << fruits[i] << " ";
//		}
//		cout << endl;
		sort(fruits+i+1, fruits+n);
	}
	for(int i = 1;i<n;i++){
		sum += fruits[i];
	}
	cout << sum << endl;
	
	return 0;
}


