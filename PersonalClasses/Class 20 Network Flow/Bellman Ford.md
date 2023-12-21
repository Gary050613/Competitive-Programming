```c++
#include<iostream>
using namespace std;
int main(){
	/*
	Bellman-Ford
		外循环 n-1次 ，n为顶点个数
		内循环 m 次，m 是边的个数
		dis[]：记录源点到其余各个顶点的最短路径
		u,v,w：记录边的信息
		例子：第 i 条边储存在 u[i]/v[i]/w[i]
			  表示从顶点 u[i] 到顶点v[i] 的这条边权值为 w[i]
			  
		if(dis[v[i]] > dis[u[i]] + w[i])
				dis[v[i]] = dis[u[i]] + w[i];
			看能否通过 u[i]->v[i] 的这条边使得 1 号顶点到 v[i]的距离缩短 
			即
			1号顶点到 u[i] 的距离 dis[u[i]] 
			加上
			u[i]->v[i]的这条边的值 w[i] 
			是否会比原先的 1 号顶点到 v[i]的距离 dis[v[i]]的值更小 
			   
	*/
	int dis[10],i,k,n,m,flag;
	int u[10],v[10],w[10];
	int inf = 99999;
	cin>> n >> m;
	
	for(i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
	} 
	for(i = 1; i <= n; i++){
		dis[i] = inf;
	}
	dis[1] = 0;
	
	for(k = 1; k <= n-1; k++)
		for(i = 1; i <= m; i++)
			if(dis[v[i]] > dis[u[i]] + w[i])
				dis[v[i]] = dis[u[i]] + w[i];
	flag = 0;
	for(i = 1; i <=m;i++){
		if(dis[v[i]] > dis[u[i]] + w[i]){
			flag = 1;
		}
	}
	if(flag) break;
	for(i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}
		
	

	return 0;
}
```

