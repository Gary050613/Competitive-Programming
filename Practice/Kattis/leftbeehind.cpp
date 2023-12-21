#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, y;
	while(cin >> x >> y && (x!=0 || y!=0)){
		if(x + y == 13){
			cout << "Never speak again.\n";
		}else if(y > x){
			cout << "Left beehind.\n";
		}else if(x > y){
			cout << "To the convention.\n";
		}else{
			cout << "Undecided.\n";
		}
	}
	return 0;
}


