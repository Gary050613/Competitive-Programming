#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	
	int n, m, arr[100001], v[100001] = {0}, ans = 0;
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr, arr+n, cmp);
	for(int i = 0;i<n;i++){
		if(v[i]){
			continue;
		}
		ans++;
		int a = m-arr[i];
		for(int j = i+1;j<n;j++){
			if(a>=arr[j] && !v[j]){
				v[j] = 1;
				a -= arr[j];
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
/*
5 6
4 2 4 5 1
*/

