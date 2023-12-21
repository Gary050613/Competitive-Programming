#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool boring(ll n){
	string str = to_string(n);
	for(int i = 1;i<=str.length();i++){
		if((i%2==0 && (str[i-1]-48)%2==1) || (i%2==1 && (str[i-1]-48)%2==0)){
			return false;
		}
	}
	return true;
}

int main(){

	int t;
	ll l, r;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
    	ll ans = 0;
    	cin >> l >> r;
    	for(ll j = l;j<=r;j++){
    		if(boring(j)){
    			ans++;
			}
		}
    	cout << "Case #" << i << ": " << ans << endl;
    }

	return 0;
}


