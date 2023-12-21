#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, direction;
	string name;
	deque<string> dq;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> direction >> name;
		if(direction == 0){
			dq.push_front(name);
		}else{
			dq.push_back(name);
		}
	}
	while(!dq.empty()){
		cout << dq.front() << endl;
		dq.pop_front();
	}

	return 0;
}


