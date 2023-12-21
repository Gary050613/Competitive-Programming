#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string arr[21], inc[21], dec[21];
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> arr[i];
		inc[i] = arr[i];
		dec[i] = arr[i];
	}
	sort(inc, inc+n);
	sort(dec, dec+n);
	reverse(dec, dec+n);
	bool flag = 0;
	for(int i = 0;i<n;i++){
		if(arr[i]!=inc[i]) break;
		if(i == n-1) {
			cout << "INCREASING\n";	
			flag = 1;
		}
	}
	for(int i = 1;i<n;i++){
		if(arr[i]!=dec[i]) break;
		if(i == n-1){
			cout << "DECREASING\n";
			flag = 1;
		} 
	}
	if(flag == 0){
		cout << "NEITHER\n";
	}
	
	return 0;
}


