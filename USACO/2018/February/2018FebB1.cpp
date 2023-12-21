#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ofstream cout("teleport.out");
	ifstream cin("teleport.in");
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	int ans = abs(a-b);
	ans = min(ans, abs(a-x) + abs(b-y));
	ans = min(ans, abs(a-y) + abs(b-x));
	cout << ans << endl;
	
	return 0;
}


