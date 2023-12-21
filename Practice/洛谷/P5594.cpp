#include <bits/stdc++.h>
using namespace std;
int tests[1001][1001]={0}, ans[1001] = {0};
int main(){
	
	int n, m, k, a;
	scanf("%d %d %d", &n, &m, &k);
	while(n--){
		for(int i = 1;i<=m;i++){
			scanf("%d", &a);
			tests[i][a] = 1;
		}
	}
	for(int i =1;i<=k;i++){
		for(int j = 1;j<=m;j++){
			if(tests[j][i]){
				ans[i]++;
			}
		}
	}
	for(int i = 1;i<=k;i++){
		printf("%d ", ans[i]);
	}
	
	return 0;
}


