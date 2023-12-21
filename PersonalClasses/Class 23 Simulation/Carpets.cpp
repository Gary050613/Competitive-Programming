#include <bits/stdc++.h>
using namespace std;

struct carpet{
	int a, b, x, y;
} c[101];

int main(){
	
	int n, tx, ty;
	cin >> n;
	for(int i = 1;i<=n;i++){
		scanf("%d %d %d %d", &c[i].a, &c[i].b, &c[i].x, &c[i].y);
	}
	cin >> tx >> ty;
	for(int i = n;i>=1;i--){
		if(tx >= c[i].a && ty >= c[i].b && tx <= c[i].a+c[i].x && ty <= c[i].b+c[i].y){
			printf("%d\n", i);
			break;
		}
		if(i == 1){
			printf("-1\n");
			break;
		}
	}
	
	return 0;
}


