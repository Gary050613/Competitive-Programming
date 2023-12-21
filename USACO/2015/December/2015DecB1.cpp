#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ofstream cout ("paint.out");
	ifstream cin ("paint.in");
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if((d>a && c>=b) || (a>=d && b>c)){ // a b c d | c d a b
		cout << (d-c)+(b-a) << endl;
	}else{ // a c b d | c a d b
		int start = min(a,c);
		int end = max(b,d);
		cout << end-start << endl;
	}
	
	return 0;
}


