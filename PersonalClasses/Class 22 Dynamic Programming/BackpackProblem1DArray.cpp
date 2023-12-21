#include<iostream>
#include<cstdio>
using namespace std;
const int maxm = 2001,maxn=31;
int m,n;
int w[maxn],c[maxn];
int f[maxm];
int main(){
	//???? m ? ???? n 
	scanf("%d%d",&m,&n);
	//??????????,?????????? 
	for(int i = 1; i <= n; i++){
		//?????????? 
		scanf("%d%d",&w[i],&c[i]);
	}
	for(int i = 1; i <= n; i++){
		for(int v = m; v >= w[i];v--){
			//max(f[v],f[v-w[i]]+c[i])  (v>=w[i] 1<=i<=n)
			if(f[v-w[i]]+ c[i] > f[v]){
//				for(int j = 1;j<=m;j++){
//					cout << f[j] << " ";
//				}
				cout << endl;
				f[v] = f[v-w[i]] + c[i];
			} 
		}
	}
	//f[m] ????? 
	printf("%d",f[m]);

	return 0;
}
