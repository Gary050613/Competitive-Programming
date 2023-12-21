#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string seq;
	bool left = 0;
	while(cin >> seq && seq != "99999"){
		int num = seq[0] + seq[1] - '0' - '0';
		if(num % 2 == 1){
			left = 1;
			cout << "left " << seq.substr(2,3) << endl;
		}else if(num % 2 == 0 && num != 0){
			left = 0;
			cout << "right " << seq.substr(2,3) << endl;
		}else{
			if(left){
				cout << "left " << seq.substr(2,3) << endl;
			}else{
				cout << "right " << seq.substr(2,3) << endl;
			}
		}
	}
	
	return 0;
}


