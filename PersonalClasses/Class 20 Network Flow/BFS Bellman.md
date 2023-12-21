```c++
#include<iostream>
using namespace std;
int main(){
	
	int n,m,i,j,k;
	//根据实际情况申请  最大大小 +1 
	int u[8],v[8],w[8];
	//first 比 n 的最大值+1
	//next 比 m 的最大值+1 
	int first[6],next[8];
	//book 记录数组哪些点已经在队列中了 
	int dis[6] = {0},book[6] = {0}; 
	//定义一个队列，并初始化
	int que[101] = {0},head = 1,tail = 1;
	int inf = 99999;
	
	cin >> n >> m;
	//初始化 dis 数组（从1号顶点 到各个顶点的初始的路程）
	for(i=1;i<=n;i++){
		dis[i] = inf;
	} 
	dis[1] = 0;
	//book数组初始化，表示所有的点都不在队列中
	for(i = 1; i <=n;i++) book[i] = 0;
	//first数组，下标 1 ~ n 的所有点为 -1，所有的点暂时都没有边 
	for(i = 1; i <= n; i++) first[i] = -1;
	//读边 
	for(i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
		//邻接表关键
		next[i] = first[u[i]]; 
		first[u[i]] = i;
	}
	//开始入队
	que[tail] = 1;
	tail++;
	//1号已经入队 
	book[1] = 1; 
	//队列不为空的时候循环 
	while(head < tail){
		//处理队首顶点 
		k = first[que[head]]; 
		//扫描当前顶点的所有的边
		while(k != -1){
			//判断是否能够松弛成功 
			if(dis[v[k]] > dis[u[k]] + w[k]){
				//更新顶点 1 到顶点 v[k] 的路程
				dis[v[k]] = dis[u[k]] + w[k];
				//判断顶点 v[k] 是否在队列中
				if(book[v[k]] == 0){
					//如果为 0 ，表示不在队列中，将顶点 v[k] 放入队列中
					que[tail] = v[k];
					tail++;
					//标记顶点 v[k] 这一项已经进入队列中 
					book[v[k]] = 1; 
				} 
			}
			k = next[k]; 
		} 
		//出队 
		book[que[head]] = 0;
		head++;
	} 
	
	for(i = 1; i <= n; i++) {
		cout << dis[i] << " "; 
	} 

	return 0;
}
```

