/*
ID: gary0501
TASK: ride
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    char a[7], b[7];
    int a1 = 1, b1 = 1;
    fin >> a >> b;
    for(int i = 0;i<strlen(a);i++) {
    	a1 *= a[i] - 64;
	}
	for(int i = 0;i<strlen(b);i++) {
    	b1 *= b[i] - 64;
	}
	if(a1 % 47 == b1 % 47) {
		fout << "GO" << endl;
	}else{
		fout << "STAY" << endl;
	}
    return 0;
}
