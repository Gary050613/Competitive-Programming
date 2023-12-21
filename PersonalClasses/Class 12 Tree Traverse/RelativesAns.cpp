#include<iostream>
using namespace std;
const int Max = 20001;
int f[Max];
int i,x,y,n,m,q; 

//????(??????,??????) 
int getf(int v){
	if(f[v] == v){
		return v;
	}
	else{
		f[v] = getf(f[v]);
		return f[v];
	}
}
//?????? 
void merge(int x, int y){
	int t1,t2;
	t1 = getf(x);
	t2 = getf(y);
	if(t1 != t2){
		f[t2] = t1;
	}
	return;
}
int main(){

	cin >> n >> m;
	for(i = 1; i <= n; i++){
		f[i] = i;
	}
	for(i = 1; i <= m; i++){
		cin >> x >> y;
		int r1 = getf(x);
		int r2 = getf(y);
		if(r1 != r2) merge(r1,r2);
	}
	cin >> q;
	for(i = 1; i <= q; i++){
		cin >> x >> y;
		if(getf(x) == getf(y)){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}

	return 0;
}
