#include <bits/stdc++.h>
using namespace std;
int n, cap=20, low=0; string str;
int main(){
	while(cin >> n && n){
		getline(cin, str);
		getline(cin, str);
		if(str == "too high") cap = min(cap, n);
		else if(str == "too low") low = max(low, n);
		else if(str == "right on"){
			if(n > low && n < cap) cout << "Stan may be honest\n";
			else cout << "Stan is dishonest\n";
			cap = 20, low = 0;
		}
	}
	return 0;
}


