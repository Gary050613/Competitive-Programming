#include<iostream>
using namespace std;
int bfs(){
	int i,j,k,v,u;
	memset(pre,-1,sizeof(pre));
	for(i = 1; i <= n; ++i){
		flow[i] = 99999;
	}
	queue<int> que;
	pre[start] = 0;
	que.push(start);
	while(!que.empty()){
		v = que.front;
		que.pop();
		for(i = 1; i <= n; i++){
			u = i;
			if(u == start || pre[u] != -1 || map[v][u] == 0){
				continue;
			}
			pre[u] = v;
			flow[u] = min(flow[v],map[v][u]);
			que.push(u);
		}
	}
	if(flow[end] == 99999){
		return -1;
	}
	return flow[end];
}
int main(){

	return 0;
}
