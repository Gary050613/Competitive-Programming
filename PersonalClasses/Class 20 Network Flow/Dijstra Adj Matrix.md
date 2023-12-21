```c++
#include<iostream>
using namespace std;
int main(){
	
	int e[10][10],dis[10],book[10],i,j,n,m,t1,t2,t3,u,v,min;
	int INF = 99999;
	cin >> n >> m;
	//初始化 
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(i == j){
				e[i][j] = 0;
			}
			else{
				e[i][j] = INF;
			}
		}
	}
	//读入当前的边 
	for(i = 1; i <= m; i++){
		cin >> t1 >> t2 >> t3;
		e[t1][t2] = t3;
	}
	//dis数组
	for(i = 1; i <= n; i++){
		//这里是 1号顶点到其他各个顶点的初始路程 
		dis[i] = e[1][i];
	} 
	//book 数组
	for(i = 1; i <= n; i++){
		book[i] = 0;
	} 
	book[1] = 1;
	//Dijkstra
	for(i = 1; i <= n-1; i++){
		//先找距离 1号顶点最近的顶点
		min = INF;
		for(j = 1; j <= n; j++){
			if(book[j] == 0 && dis[j] < min){
				min = dis[j];
				u = j;
			}
		} 
		book[u] = 1;
		for(v = 1;v<=n; v++){
			if(e[u][v] < INF){
				if(dis[v] > dis[u] + e[u][v]){
					dis[v] = dis[u] + e[u][v];
				}
			}
		}	
	} 
	
	for(i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}

	return 0;
}
```

