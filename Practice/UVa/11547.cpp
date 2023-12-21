#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << abs(((n*315+36962)%100)/10) << endl;
	}
	return 0;
}


