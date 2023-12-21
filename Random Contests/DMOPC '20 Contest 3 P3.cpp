#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	
	ll Q, N, M, K, B, ans=0;
	cin >> Q;
	while(Q--){
		cin >> N >> M >> K >> B;
		if(M==1 && K==1 && N%3==0){
			int t = 1;
			for(int i = 0;i<N/3;i++){
				ans = ans + t*pow(B,i);
			}
			cout << ans << endl;
		}
		else if((N*M)%(K+2) == 0){
			int t = (N*M)/(K+2)/N;
			for(int i = 0;i<N;i++){
				ans = ans + t*pow(B,i);
			}
			cout << ans << endl;
		}else{
			cout << -1 << endl;
		}
	}
	
	return 0;
}


