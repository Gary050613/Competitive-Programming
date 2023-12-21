#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cost=0, cur;
int main(){
	
	scanf("%lld", &cur);
	if(cur == 1){
		printf("0");
	}else{
		int a, b;
		while(cur > 2){
			int n = sqrt(cur)+1;
			for(int i = 2;i<=n;i++){
				if(cur % i == 0){
					if((cur / i) > i){
						a = cur/i;
						b = i;
					}else{
						a = i;
						b = cur/i;
					}
					cost += b-1;
					cur -= a;
	//				cout << "Cur: " << cur << " Cost: " << cost << endl;
					break;
				}
				if(i == n){
					cost += cur-1;
					cur -= 1;
					break;
				}
			}
		}
		printf("%lld", cost+1);
	}
	
	
	return 0;
}


