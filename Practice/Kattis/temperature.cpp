#include <bits/stdc++.h>
using namespace std;

int main(){
	double X, Y;
	cin >> X >> Y;
	if(X == 0 && Y == 1){
		cout << "ALL GOOD\n";
	}else if(Y == 1){
		cout << "IMPOSSIBLE\n";
	}else{
		cout << printf("%.7f", X/(1-Y)) << endl;
	}
	return 0;
}


