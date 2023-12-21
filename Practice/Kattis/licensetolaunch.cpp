#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, a, cur=100001, curD;
	cin >> N;
	for(int i = 0;i<N;i++){
		cin >> a;
		if(a < cur){
			cur = a;
			curD = i;
		}
	}
	cout << curD << endl;
	return 0;
}


