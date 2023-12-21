```c++
#include<iostream>
#define maxn 220
#define INF 0x7f
using namespace std;
int cap[maxn][maxn],flow[maxn][maxn];
int pre[maxn],res[maxn];// res[i]去记录残量 
int Edmond_Karp(int start,int end){
	int maxflow = 0;
	memset(flow,0,sizeof(flow));
	memset(pre,0,sizeof(pre));
	queue<int> que;
	while(1){
		memset(res,0,sizeof(res));
		res[start] = INF;
		que.push(start);
		while(!que.empty()){
			int u = que.front;
			que.pop();
			for(int v = 1; v <= end; v++){
				if(!res[v] && cap[u][v] > flow[u][v]){
					//start - v 路径上最小的残量 
					res[v] = min(res[u],cap[u][v] - flow[u][v]);
					//记录 v 的父亲，并加入到队列中 
					pre[v] = u;
					que.push(); 
				}
			}
		}
		if(res[end] == 0){
			//无法继续更新最大流量，当前流已经是最大流 
			return maxflow;
		}
		//从汇点开始往回走 
		for(int u = end; u != start;u = pre[u]){
			//更新正向流 
			flow[pre[u]][u] += res[end]; 
			//更新反向流
			flow[u][pre[u]] -= res[end]; 
		} 
		//更新从 s 流出的总流量 
		maxflow = maxflow + res[end];
	}
}
int main(){
	
	memset(cap,0,sizeof(cap));
	
	for(){
		int u,v,s;
		cin >> u >> v >> s;
		//重边 
		cap[u][v] += s;
	} 

	return 0;
}
```

