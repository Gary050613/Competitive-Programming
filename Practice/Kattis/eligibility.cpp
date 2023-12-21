#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, PYY, PMM, PDD, BYY, BMM, BDD, c;
	char ch;
	string s;
	cin >> n;
	while(n--){
		cin >> s >> PYY >> ch >> PMM >> ch >> PDD >> BYY >> ch >> BMM >> ch >> BDD >> c;
		if(PYY >= 2010 || BYY >= 1991){
			cout << s << " eligible\n";
		}else if(c >= 41){
			cout << s << " ineligible\n";
		}else{
			cout << s << " coach petitions\n";
		}
	}
	return 0;
}


