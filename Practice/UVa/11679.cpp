#include <bits/stdc++.h>
using namespace std;

int main(){
	int B, N, R[21], D, C, V, balance[21]={0};
	while(cin >> B >> N && (B||N)){
		memset(balance, 0, sizeof(balance));
		for(int i = 1;i<=B;i++){
			cin >> R[i];
		}
		while(N--){
			cin >> D >> C >> V;
			balance[D] -= V;
			balance[C] += V;
		}
		for(int i = 1;i<=B;i++){
			R[i] += balance[i];
//			cout << R[i] << " ";
			if(R[i] < 0){
				cout << "N\n";
				break;
			}
			if(i == B){
				cout << "S\n";
			}
		}
	}
	return 0;
}


