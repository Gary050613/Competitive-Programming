#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ifstream cin ("promote.in");
	ofstream cout ("promote.out");
	int n[8], ans[3] = {0};
	for(int i = 0;i<8;i++){
		cin >> n[i];
	}
	ans[2] += n[7]-n[6];
	n[5] += n[7]-n[6];
	ans[1] += n[5]-n[4];
	n[3] += n[5]-n[4];
	ans[0] += n[3]-n[2];
	for(int i = 0;i<3;i++){
		cout << ans[i] << endl;
	}
	
	return 0;
}


