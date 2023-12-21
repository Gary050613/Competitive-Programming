#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ifstream cin ("word.in");
	ofstream cout ("word.out");
	int n, k, size=0;
	string input;
	cin >> n >> k;
	getline(cin, input);
	getline(cin, input);
	stringstream ss(input);
	string cur, line="";
	while(ss >> cur){
		if(size + cur.length() > k){
			cout << line << endl;
			size = 0;
			line = "";
		}
		if(size == 0){
			line = cur;
			size += cur.length();
		}else if(size + cur.length() <= k){
			line += " " + cur;
			size += cur.length();
		}
	}
	cout << line << endl;
	
	return 0;
}


