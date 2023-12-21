#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int l, m, a, b;
	bool trees[10001] = {0};
	scanf("%d %d", &l, &m);
	int ans = l+1;
	while(m--){
		scanf("%d %d", &a, &b);
		for(int i = a;i<=b;i++){
			trees[i] = 1;
		}
	}
	for(int i = 0;i<=l;i++){
		if(trees[i]) ans--;
	}
	printf("%d\n", ans);
	
	return 0;
}


