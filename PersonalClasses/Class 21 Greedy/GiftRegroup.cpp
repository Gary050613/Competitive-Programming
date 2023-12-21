#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	
	int w, n, arr[30001], v[30001] = {0}, ans = 0;
	cin >> w >> n;
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr, arr+n, cmp);
	for(int i = 0;i<n;i++){
		if(v[i]) continue;
		for(int j = i+1;j<n;j++){
			if(!v[j] && arr[i] + arr[j] < w){
				v[j] = 1;
				j = n;
			}
		}
		ans++;
	}
	cout << ans << endl;
	
	return 0;
}

/*
100
9
90
20
20
30
50
60
70
80
90
*/
