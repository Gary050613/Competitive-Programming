#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, m;
	cin >> n >> m;
	queue<int> q;
	int arr[101];
	for(int i = 1;i<=n;i++){
		q.push(i);
	}
	for(int kicked = 1;kicked<n;kicked++){
		for(int j = 0;j<m-1;j++){
			q.push(q.front());
			q.pop();
		}
		q.pop();
	}
	cout << q.front();

	return 0;
}

