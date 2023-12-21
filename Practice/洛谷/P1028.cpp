#include <bits/stdc++.h>
using namespace std;
int f[1001];
int main(){
	
	int n;
	scanf("%d", &n);
	f[1] = 1;
	for(int i = 2;i<=n;i++){
		int a = 0;
		for(int j = 1;j<=i/2;j++){
			a += f[j];
		}
		f[i] = a+1;
	}
	printf("%d", f[n]);
	
	return 0;
}


