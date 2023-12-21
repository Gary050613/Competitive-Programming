#include <bits/stdc++.h>
using namespace std;

int main(){
	int ans=0;
	string card;
	map<char, int> mp;
	for(int i = 0;i<5;i++){
		cin >> card;
		mp[card[0]]++;
		ans = max(ans,mp[card[0]]);
	}
	cout << ans << endl;
	return 0;
}


