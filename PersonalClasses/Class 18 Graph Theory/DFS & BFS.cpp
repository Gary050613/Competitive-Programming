#include <bits/stdc++.h>
using namespace std;
bool visited[1001] = false;
int q[1001]={0}, g[1001][1001];

void dfs(int i){
	visited[i] = true;
	for(int j = 1;j<=n;j++){
		if(g[i][j]==1 && visited[j] == 0){
			dfs(j);
		}
	}
}

void bfs(int i){
	int head, tail;
	head = 0;
	tail = 1;
	visited[i] = 1;	
	while(head < tail){
		int k = q[head];
		for(int j = 1;j<=n;j++){
			if(g[k][j] == 1 && visited[k] == 0){
				visited[j] = 1;
				q[++tail] = j;
			}
		}
		head++;
	}
}

int main(){
	
	
	
	return 0;
}


