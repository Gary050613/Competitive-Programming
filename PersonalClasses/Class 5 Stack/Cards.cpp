#include <bits/stdc++.h>
using namespace std;

int main(){

	queue<int> q;
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		q.push(i);
	}
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
		q.push(q.front());
		q.pop();
	}

	return 0;
}

