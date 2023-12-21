#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	
	int T;
	cin >> T;
	while(T--){
		ll a[4];
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a+3);
		ll sum = (a[0] * a[0]) + (a[1] * a[1]);
		ll sq = a[2] * a[2];
		if(sum == sq){
			cout << "R" << endl;
		}else if(sum < sq){
			cout << "O" << endl;
		}else if(sum > sq){ 
			cout << "A" << endl;
		}
	}
	
	return 0;
}


