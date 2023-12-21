#include<iostream>
using namespace std;
struct data{
	int x,y,t;
} a[10001];
const int Max = 20001;
int f[Max];
int n,m,t; 
void qsort(int l, int r){
	if(l >= r) return;
	int i = l,j = r;
	data x = a[i];
	while(i < j){
		while(i < j && x.t <= a[j].t) j--;
		a[i] = a[j];
		while(i < j && x.t >= a[i].t) i++;
		a[j] = a[i];
	}
	a[i] = x;
	qsort(l,i-1);
	qsort(i+1,r);
} 
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
// ?? 
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

	int i,x,y,sum = 0,tx;
	cin >> n >> m;
	for(i = 1; i <= n; i++){
		f[i] = i;
	}
	for(i = 1; i <= m; i++){
		cin >> a[i].x >> a[i].y >> a[i].t;
	}
	qsort(1,n);
	tx = n;
	for(i = 1;i <= m; i++){
		if(getf(a[i].x) != getf(a[i].y)){
			merge(a[i].x,a[i].y);
			tx--;
		}
		if(tx == 1){
			cout << a[i].t << endl;
			return 0;
		}
	}
	cout << "-1" << endl;

	return 0;
}
