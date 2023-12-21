#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(cin >> s && s != "END"){
		if(s == "1"){
			cout << 1 << endl;
			continue;
		}
		int i = 0, x = 0;
		while(x != 1){
			x = s.length();
			s = to_string(x);
			i++;
		}
		cout << i+1 << endl;
	}
	return 0;
}


