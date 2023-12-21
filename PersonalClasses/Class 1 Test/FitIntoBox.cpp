#include <bits/stdc++.h>
using namespace std;

int main(){
	int A1, A2, A3, A4, A5, A6, n;
	cin >> A1 >> A2 >> A3 >> A4 >> A5 >> A6;
	n = A6 + A5 + A4;
	A1 -= 11 * A5;
	A2 -= 5 * A4;
	if(A2 < 0) {
		A1 += A2 * 4;
		A2 = 0;
	}
	n += A3/4;
	A3 %= 4;
	
	cout << n;
	return 0;
}

