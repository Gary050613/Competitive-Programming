#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	
	ll n, arr[100001], v[100001], ans = 0;
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
	}
	for(int i = 1;i<=n;i++){
		ans+=v[i]%1000000007;
	}
	cout << ans-1 << endl;
	
	return 0;
}


