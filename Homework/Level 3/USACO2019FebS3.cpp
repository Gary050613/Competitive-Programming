#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, M, p[2*MM], con[MM], cnt=0; char op;
int fd(int d, int p[]) {
	return d==p[d]?p[d]:p[d]==fd(p[d],p);
}
int main(){
	cin >> N >> M; cnt == N;
	for(int i=1;i<=N;i++){
		p[i]=i;con[i]=i;p[i+N]=i+N;
	}
	for(int i=1, u, v;i<=M;i++){
		cin >> op >> u >> v;
		int su = find(u,p), sv = fd(v,p), du = fd(u+N, p), dv = fd(v+N, p);
		if(op=='S'){
			if(su==dv || sv == du){
				cout << 0 << endl; return 0;
			}
			p[su] = sv, p[du] = dv;
		} else {
			if(su == du || sv == dv){
				cout << 0 << endl; return 0;
			}
			p[su] = dv, p[sv] = du;
		}
	}
	return 0;
}


