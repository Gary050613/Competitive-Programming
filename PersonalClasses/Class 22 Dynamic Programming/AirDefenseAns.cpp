#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
int main(){

	int i,j,k,x,n,maxx,m,a[10001],b[10001],h[10001];
	i = 1;
	n = 0;
	m = 0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(h,0,sizeof(h));
	
	while(cin >> a[i]){
		maxx = 0;
		for(j = 1; j <= i -1; j++){
			if(a[j] >= a[i]){
				if(b[j] > maxx){
					maxx = b[j];
				}
			}
		}
		b[i] = maxx + 1;
		if(b[i] > m){
			m = b[i];
		}
		x = 0;
		for(k = 1; k <= n; k++){
			if(h[k] >= a[i]){
				if(x == 0){
					x = k;
				}
				else if(h[k] < h[x]){
					x = k;
				}
			}
		}
		if(x == 0){
			n++;
			x = n;
		}
		h[x] = a[i];
		i++;
	}
	cout << m << endl;
	cout << n << endl;
	return 0;
}
