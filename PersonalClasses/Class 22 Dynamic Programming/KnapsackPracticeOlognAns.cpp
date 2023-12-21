#include<iostream>
#include<cstdio> 
using namespace std;
int v[10001],w[10001];
int f[6002];
int n,m,nl;
int max(int x,int y){
	if(x < y){
		return y;
	}
	else{
		return x;
	}
}

int main(){
	
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n; i++){
		int x,y,s,t=1;
		scanf("%d%d%d",&x,&y,&s);
		while(s >= t){
			v[++nl] = x * t;
			w[nl] 	= y * t;
			s -= t;
			t *= 2;
		}
		v[++nl] = x * s;
		// s ? 2 ?????(1,2,4,... ,2^(k-1),s - 2^k + 1) 
		w[nl] 	= y * s;
	}
	for(int i = 1 ; i <= nl; i++){
		for(int j = m ; j >= v[i]; j--){	
			f[j] = max(f[j],f[j-v[i]]+w[i]);	
		}	
	}
	printf("%d",f[m]);
	/*
		O(V* n[i]) --> O(V * logn[i]) 
	*/

	return 0;
}
