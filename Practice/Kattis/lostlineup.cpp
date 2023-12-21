#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[101], n, a;
	arr[1] = 1;
	cin >> n;
	for(int i = 2;i<=n;i++){
		cin >> a;
		arr[a+2] = i;
	}
	for(int i = 1;i<=n;i++){
		cout << arr[i] << " ";
	}
	return 0;
}


