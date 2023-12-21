```c++
/*
记最短路径为  dis[i][j],g[i][j] 为 边<i,j>的权值

环中最大的节点 k（编号最大），与它相连的是 i ，j
这个环最短长度为 g[i][k] 
			   + g[k][j]
			   +(i到j路径中所有节点编号
			    都小于k 的最短路径长度) 
 
*/
for(k = 1; k <= n;k++){
	for(i = 1; i <= k-1;i++){
		for(j = i + 1; j <= k-1; j++){
			answer = min(answer,dis[i][j] + g[j][k] + g[k][i]);
		}
	}
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			dis[i][j] = min(dis[i][k],dis[i][k]+dis[k][j]);
		}
	}
}
```

