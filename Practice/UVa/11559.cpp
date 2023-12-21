#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, B, H, W, p, a;
	while(cin >> N >> B >> H >> W) {
		int ans = 500001;
		while(H--){
			cin >> p;
			for(int i = 0;i<W;i++){
				cin >> a;
				if(a >= N && N*p <= B){
					ans = min(ans, N*p);
				}
			}
		}
		if(ans == 500001){
			cout << "stay home\n";
		}else{
			cout << ans << endl;
		}
	}
	return 0;
}


