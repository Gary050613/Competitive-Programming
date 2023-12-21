#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, a, train;
	cin >> n;
	stack<int> s;
	queue<int> q;
	for(int i = 0;i<n;i++){
		cin >> a;
		q.push(a);
	}
	for(int i = 1;i<=n;i++){
		s.push(i);
		while(!s.empty() && s.top() == q.front()){
			s.pop();
			q.pop();
		}
	}
	if(q.empty()){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

	return 0;
}

