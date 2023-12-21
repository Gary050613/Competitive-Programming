#include <bits/stdc++.h>
using namespace std;
const int unvisited = -1;
int n, m, value[101], visited[101] = {0};
vector<int> g[101];
int id = 0, sccCount = 0;
int ids[101], low[101];
bool onStack[101];
stack<int> s;

void dfs(int at){
	s.push(at);
	onStack[at] = true;
	ids[at] = low[at] = id++;
	for(auto i = g[at].begin(); i!=g[at].end();i++){
		if(ids[*i] == unvisited) dfs(*i);
		if(onStack[*i]){
			low[at] = min(low[at],low[*i]);
		}
	}
	if(ids[at] == low[at]){
		for(int i = s.top();;){
			s.pop();
			onStack[i] = false;
			low[i] = ids[at];
			if(i == at) break;
		}
		sccCount++;
	}
}

void findSccs(){
	for(int i = 1;i<=n;i++){
		if(ids[i] == unvisited){
			dfs(i);
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> value[i];
		ids[i] = unvisited;
	}
	int u, v;
	for(int i = 1;i<=m;i++){
		cin >> u >> v;
		g[u].push_back(v);
	}

	memset(ids, 0, sizeof(ids));
	memset(low, 0, sizeof(low));
	memset(onStack, false, sizeof(onStack));
	findSccs();
	cout << sccCount << endl;
	
	return 0;
}


