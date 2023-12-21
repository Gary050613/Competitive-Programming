#include <bits/stdc++.h>
using namespace std;

int main(){
	string month;
	int date;
	cin >> month >> date;
	if((month == "OCT" && date == 31) || (month == "DEC" && date == 25)){
		cout << "yup\n";
	}else{
		cout << "nope\n";
	}
	return 0;
}


