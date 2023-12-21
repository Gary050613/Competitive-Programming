#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	priority_queue<pair<int, int>> pq;
	map<int, int> m;
	cin >> n;
	int ans = n;
	for(int i = 0;i<n;i++){
		int a;
		cin >> a;
		m[a]++;
	}
	for(auto p : m){
		pq.push(make_pair(p.second, p.first));
	}
	while(pq.size()>1){
		auto p1 = pq.top();
		pq.pop();
		auto p2 = pq.top();
		pq.pop();
		p1.first--, p2.first--;
		ans-=2;
		if(p1.first) pq.push(p1);
		if(p2.first) pq.push(p2);
	}
	cout << ans << endl;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}


