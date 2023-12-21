#include <bits/stdc++.h>
using namespace std;
int arr[101], v[101], ans = 0;
int main(){
	
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> arr[i];
	}
	for(int i = 1;i<=n;i++){
		int m = 0;
		for(int j = 1;j<i;j++){
			if(v[j] >= m && arr[i] >= arr[j]){
				m = v[j];
			}
		}
		v[i] = m+1;
		ans = max(ans, m+1);
	}
	cout << ans << endl;
	
	return 0;
}

/*
14
13 7 9 16 38 24 37 18 44 19 21 22 63 15
*/
