#include <bits/stdc++.h>
using namespace std;

int main(){
	int A, B, A1=0, B1=0;
	cin >> A >> B;
	A1 = (A%10*100) + ((A%100/10)*10) + (A/100);
	B1 = (B%10*100) + ((B%100/10)*10) + (B/100);
	cout << max(A1, B1) << endl;
	return 0;
}


