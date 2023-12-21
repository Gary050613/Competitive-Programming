#include <bits/stdc++.h>
using namespace std;

int main(){
	int g, s, c, t;
	cin >> g >> s >> c;
	t = g*3 + s*2 + c;
	if(t >= 8){
		cout << "Province or ";
	}else if(t >= 5){
		cout << "Duchy or ";
	}else if(t >= 2){
		cout << "Estate or ";
	}
	if(t >= 6){
		cout << "Gold\n";
	}else if(t >= 3){
		cout << "Silver\n";
	}else{
		cout << "Copper\n";
	}
	return 0;
}


