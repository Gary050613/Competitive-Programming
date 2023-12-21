#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll curS[500001], ans[500001] = {0};
int main(){
	
	int n, q, a, l, r;
	ll w;
	cin >> n >> q;
	for(int i = 1;i<=n;i++){
		cin >> curS[i];
		ans[i] = 0;
	}
	while(q--){
		cin >> a;
		if(a==1){
			cin >> l >> r >> w;
			for(int i = l;i<=r;i++){
				curS[i] += w;
			}
		}else if(a==2){
			cin >> l >> r;
			for(int i = l;i<=r;i++){
				ans[i] += curS[i];
			}
		}
	}
	for(int i = 1;i<=n;i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}


