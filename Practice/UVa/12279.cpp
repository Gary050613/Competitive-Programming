#include <bits/stdc++.h>
using namespace std;

int main(){
	int cnt=1, ans=0, a, N;
	while(cin >> N && N!=0){
		ans = 0;
		while(N--){
			cin >> a;
			if(a == 0) ans--;
			else ans++;
		}
		printf("Case %d: %d\n", cnt++, ans);
	}
	return 0;
}


