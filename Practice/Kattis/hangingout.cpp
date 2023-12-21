#include <bits/stdc++.h>
using namespace std;

int main(){
	int L, x, n, cur=0, ans=0;
	string status;
	cin >> L >> x;
	while(x--){
		cin >> status >> n;
		if(status=="enter"){
			if(cur+n>L){
				ans++;
				continue;
			}else{
				cur+=n;
			}
		}else{
			cur -= n;
		}
	}
	cout << ans << endl;
	return 0;
}


