#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, m, out[100001], cur = 0;
	string jobs[100001];
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> out[i] >> jobs[i];
	}
	int right = 0, moves;
	for(int i = 0;i<m;i++){
		cin >> right >> moves;
		if(out[cur]){
			if(right){
				cur = (cur+n-moves)%n;
			}else{
				cur = (cur+n+moves)%n;
			}
		}else{
			if(right){
				cur = (cur+n+moves)%n;
			}else{
				cur = (cur+n-moves)%n;
			}
		}
	}
	cout << jobs[cur] << "\n";
	
	return 0;
}

