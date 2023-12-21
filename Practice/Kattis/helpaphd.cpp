#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b;
	char ch;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		if(s == "P=NP"){
			cout << "skipped\n";
		}else{
			stringstream ss;
			ss << s;
			ss >> a >> ch >> b;
			cout << a+b << endl;
		}
	}
	return 0;
}


