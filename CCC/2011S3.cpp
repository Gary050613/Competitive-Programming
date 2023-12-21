#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, m, x, y;
bool ans = false;

void isBlue(ll layer, ll bx, ll by, ll tx, ll ty){
	if(ans){
		return;
	}
//	printf("%d %d %d %d %d\n", layer, bx, by, tx, ty);
	if(layer == m){
		if(x >= bx && x < tx && y >= by && y < ty){
			ans = true;
		}
		return;
	}
	isBlue(layer+1, bx*5, by*5, tx*5, ty*5);
	isBlue(layer+1, bx*5+1, ty*5, bx*5+2, ty*5+1);
	isBlue(layer+1, bx*5+2, ty*5, bx*5+3, ty*5+1);
	isBlue(layer+1, bx*5+2, ty*5+1, bx*5+3, ty*5+2);
	isBlue(layer+1, bx*5+3, ty*5, bx*5+4, ty*5+1);
	
}

int main(){
	
	scanf("%lld", &T);
	while(T--){
		ans = false;
		scanf("%lld %lld %lld", &m, &x, &y);
		isBlue(0, 0, 0, 0, 0);
		if(ans){
			printf("crystal\n");
		}else{
			printf("empty\n");
		}
	}
	
	
	return 0;
}


