#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, num[10001], count[10001] = {0};
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> num[i];
		count[num[i]]++;
	}
	for(int i = 0;i<10001;i++){
		while(count[i]--){
			cout << i << " ";
		}
	}

	return 0;
}


