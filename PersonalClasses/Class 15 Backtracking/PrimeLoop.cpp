#include <bits/stdc++.h>
using namespace std;

int n, arr[17], C[17] = {0}, index = 1;

bool isPrime(int a){
	for(int i = 2;i*i<=a;i++){
		if(a % i == 0){
			return false;
		}
	}
	return true;
}

void solve(int x){
	if(x == n){
		for(int i = 1;i<=n;i++){
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(C[i] == 0 && isPrime(arr[index]+i)){
			arr[++index] = i;
			C[i] = 1;
//			for(int i = 1;i<=n;i++){
//				cout << arr[i] << " ";
//			}
//			cout << endl;
			solve(x+1);
			index--;
			C[i] = 0;
		}
	}
}

int main(){

	cin >> n;
	arr[1] = 1;
	C[1] = 1;
	solve(1);

	return 0;
}


