#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, cnt=1, k, a;
	while(scanf("%d", &n)!=EOF){
		int large=-1000001, small=1000001;
		while(n--){
			scanf("%d", &a);
			if(a>large) large = a;
			if(a<small) small = a;
		}
		printf("Case %d: %d %d %d\n", cnt++, small, large, large-small);
	}
	return 0;
}


