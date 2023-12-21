#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int N, bid=0, a;
	string ans, name;
	cin >> N;
	while(N--){
		cin >> name >> a;
		if(a > bid){
			bid = a;
			ans = name;
		}
	}
	cout << ans << endl;
	
	return 0;
}


