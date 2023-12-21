#include <bits/stdc++.h>
using namespace std;

int main(){

	ofstream cout ("test.out");
	ifstream cin ("test.in");
	
	int ans = 0, a;
	
	while(cin >> a){
		ans += a;
	}
	cout << ans;
	
	cout.close();
	cin.close();

	return 0;
}


