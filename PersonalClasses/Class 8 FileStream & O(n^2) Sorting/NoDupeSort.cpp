#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, a, count[1001] = {0}, ans = 0;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a;
		if(count[a]==0){
			ans++;
			count[a]++;
		}
	}
	cout << ans << endl;
	for(int i = 0;i<1001;i++){
		if(count[i] == 1){
			cout << i << " ";
		}
	}

	return 0;
}


