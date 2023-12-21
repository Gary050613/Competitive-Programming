#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, G, prev, a, ans;
	cin >> N;
	while(N--){
		bool flag = 0;
		cin >> G;
		cin >> prev;
		for(int i = 2;i<=G;i++){
			if(flag){
				cin >> a;
				continue;
			}
			cin >> a;
			if(a-prev != 1){
				ans = i;
				flag = 1;
			}
			prev = a;
		}
		cout << ans << endl;
	}
	return 0;
}


