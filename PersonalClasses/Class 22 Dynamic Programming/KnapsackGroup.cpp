#include<iostream>
#include<cstdio> 
using namespace std;
int v,n,t;
int w[31],c[31];
int a[11][32],f[201];
int main(){

	scanf("%d%d%d",&v,&n,&t);
	for(int i = 1; i <= n; i++){
		int p;
		scanf("%d%d%d",&w[i],&c[i],&p);
		a[p][++a[p][0]] = i;
	}
	for(int k = 1; k <= t; k++){
		for(int j = v; j >= 0; j--){
			for(int i = 1; i <= a[k][0]; i++){
				if(j >= w[a[k][i]]){
					int tmp = a[k][i];
					if(f[j] < f[j - w[tmp]] + c[tmp]){
						f[j] = f[j - w[tmp]] + c[tmp];
					}
				}
			} 
		} 
	}
	printf("%d",f[v]);

	return 0;
}
