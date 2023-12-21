/*
	?? 1 ? 0 ??? +
	?? 1 ? 1 ??? - 
	?? 0 ? 0 ??? - 
	?? 0 ? 1 ??? +
	
	????
		if(now <= 0) now +=n;
		if(now >= n) now = (now-1)%n+1 
*/ 

#include<iostream>
#include<cstdio>
using namespace std;
int n,m,now,way,which;
struct node{
	char name[100001][11];
	bool zf[100001];
}toy;
//?? 
int wz(bool zf,bool zy,int gs){
	if(zf^zy){
		return gs;
	} 
	else{
		return -gs;
	}
}
void LRZ(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i<= n; i++){
		cin >> toy.zf[i] >> toy.name[i];
	}
}
void work(){
	now = 1;
	for(int i = 1; i <= m;i++){
		scanf("%d%d",&way,&which);
		now+=wz(toy.zf[now],way,which);
		if(now <= 0) now+=n;
		if(now >= n) now = (now-1)%n+1;
	}
}
int main(){

	LRZ();
	work();
	puts(toy.name[now]);

	return 0;
}
