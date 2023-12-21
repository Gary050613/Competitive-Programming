#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, cnt=1, a, ans=0;
	cin >> T;
	while(T--){
		cin >> N;
		ans = 0;
		while(N--){
			cin >> a;
			if(a > ans) ans = a;
		}
		printf("Case %d: %d\n", cnt++, ans);
	}
	return 0;
}


