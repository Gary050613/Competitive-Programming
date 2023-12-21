#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, a;
	cin >> T;
	for(int cnt = 1;cnt<=T;cnt++){
		cin >> N;
		int M=0,J=0;
		while(N--){
			cin >> a;
			M+=a/30+1;
			J+=a/60+1;
		}
		M*=10;
		J*=15;
		if(M<J){
			printf("Case %d: Mile %d\n", cnt, M);
		}else if(M>J){
			printf("Case %d: Juice %d\n", cnt, J);
		}else{
			printf("Case %d: Mile Juice %d\n", cnt, M);
		}
	}
	return 0;
}


