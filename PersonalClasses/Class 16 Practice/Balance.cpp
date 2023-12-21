#include <bits/stdc++.h>
using namespace std;

int solve(){
	int lw, ll, rw, rl;
	cin >> lw >> ll >> rw >> rl;
	if(lw == 0){
		lw = solve();
	}
	if(rw == 0){
		rw = solve();
	}
	if(lw * ll == rw * rl){
		return lw + rw;
	}else{
		return 0;
	}
}

int main(){
	int n;
	cin >> n;
	while(n--){
		if(solve()){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}


