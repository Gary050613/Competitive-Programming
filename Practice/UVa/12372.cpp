#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, L, W, H, n=1;
	cin >> T;
	while(T--){
		cin >> L >> W >> H;
		if(L <= 20 && W <= 20 && H <= 20){
			printf("Case %d: good\n", n++);
		}else{
			printf("Case %d: bad\n", n++);
		}
	}
	return 0;
}


