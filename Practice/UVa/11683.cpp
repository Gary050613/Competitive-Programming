#include <bits/stdc++.h>
using namespace std;

int main(){
	int A, C, prev, a;
	while(cin >> A >> C && (A||C)){
		int ans = 0;
		cin >> prev;
		C--;
		while(C--){
			cin >> a;
			if(a > prev){
				ans+=a-prev;
			}
			prev=a;
		}
		ans+=A-prev;
		cout << ans << endl;
	}
	return 0;
}


