#include<iostream>
using namespace std;
const int Maxn = 1001;
const int Maxm = 100001;
struct Edge{
	int next; 
	int to;
	int dis;
}edge[Maxm];
int num,head[Maxn],n,m,u,v,d;
int add(int from,int to,int dis){
	edge[++num].next = head[from];
	edge[num].to = to;
	edge[num].dis = dis;
	head[from] = num;
}
int main(){
	cin >> n >> m;
	for(int i = 1; i<= m; i++){
		cin >> u >> v >> d;
		add(u,v,d);
	}
	cout << 1;
	for(int j = head[1];j!=0;j = edge[j].next){
		cout << "->" << edge[j].to;
	}

	return 0;
}
