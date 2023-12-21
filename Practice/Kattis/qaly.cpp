#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	double x, y, ans=0;
	while(N--){
		cin >> x >> y;
		ans += x*y;
	}
	cout << ans << endl;
	return 0;
}


