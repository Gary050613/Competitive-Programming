#include <bits/stdc++.h>
using namespace std;

int g[201][201]={0}, n, m, a, b, q[201];
int head = 0, tail = 1, visited[201] = {0};

void bfs(int i){
	visited[i] = 1;
	q[0] = i;
	while(head < tail){
		int k = q[head];
		for(int j = 1;j<=n;j++){
			if(g[k][j] == 1 && visited[j] == 0){
				visited[j] = 1;
				q[++tail] = j;
				cout << j << " ";
			}
		}
		head++;
	}
}

int main(){
	
	cin >> n >> m;
	while(m--){
		cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
	}
	int s;
	cin >> s;
	cout << s << " ";
	bfs(s);
	
	return 0;
}


