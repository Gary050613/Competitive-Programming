#include <bits/stdc++.h>
using namespace std;

int ram[101]={};

bool contain(int n, int size){
	for(int i = 0;i<size;i++){
		if(abs(ram[i]) == abs(n)){
			return true;
		}
	}
	return false;
}

int main(){

	int n, m, a;
	cin >> m >> n;
	int back = 0;
	for(int i = 0;i<n;i++){
		cin >> a;
		if(!contain(a, m)){
			ram[back%m] = a;
			back++;
		}
	}
	cout << back << endl;

	return 0;
}


