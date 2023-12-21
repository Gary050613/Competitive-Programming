#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, a, cur, high, low, cnt = 1;
	cin >> T;
	while(T--){
		cin >> N;
		high = 0, low = 0, cur = 0;
		while(N--){
			cin >> a;
			if(cur == 0) cur = a;
			else{
				if(a > cur){
					high++;
					cur = a;
				}else if(a < cur){
					low++;
					cur = a;
				}
			}
		}
		printf("Case %d: %d %d\n", cnt++, high, low);
	}
	return 0;
}


