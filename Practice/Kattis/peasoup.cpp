#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	bool pan=0, pea=0;
	string name, item;
	cin >> n;
	while(n--){
		cin >> k;
		getline(cin, name);
		pan = 0, pea = 0;
		getline(cin, name);
		while(k--){
			getline(cin, item);
			if(item == "pancakes"){
				pan = 1;
			}else if(item == "pea soup"){
				pea = 1;
			}
		}
		if(pan && pea){
			cout << name << endl;
			break;
		}
		if(n==0){
			cout << "Anywhere is fine I guess\n";
		}
	}
	return 0;
}


