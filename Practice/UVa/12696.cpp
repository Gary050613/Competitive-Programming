#include <bits/stdc++.h>
using namespace std;

int main(){
	int ans=0,T;
	double l, h, d, w;
	cin >> T;
	while(T--){
		cin >> l >> h >> d >> w;
		if(l+h+d > 125){
			if(l<=56 && h<=45 && d<=25 && w<=7){
				cout << 1 << endl;
				ans++;
			}else{
				cout << 0 << endl;
			}
		}else if(w<=7){
			cout << 1 << endl;
			ans++;
		}else{
			cout << 0 << endl;
		}
	}
	cout << ans << endl;
	return 0;
}


