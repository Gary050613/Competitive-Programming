#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, X1, X2, Y1, Y2;
	char a, b;
	cin >> T;
	while(T--){
		cin >> a >> X1 >> b >> X2;
		Y1 = a-'A'+1, Y2 = b-'A'+1;
		if(((X1+Y1)%2)!=((X2+Y2)%2)){
			cout << "Impossible\n";
		}else if(X1==X2&&Y1==Y2){
			cout << "0 " << a << " " << X1 << endl;
		}else if(((X1-Y1)==(X2-Y2))||((X1+Y1)==(X2+Y2))){
			cout << "1 " << a << " " << X1 << " " << b << " " << X2 << endl;
		}else{
			int sum1 = X1+Y1, diff1 = X1-Y1, sum2 = X2+Y2, diff2 = X2-Y2;
			// MID
			// sum == sum1 && diff == diff2
			int MX1 = (sum1+diff2)/2, MY1 = (sum1-diff2)/2;
			// sum == sum2 && diff == diff1
			int MX2 = (sum2+diff1)/2, MY2 = (sum2-diff1)/2;
			if(MX1 >= 1 && MX1 <= 8 && MY1 >= 1 && MY1 <= 8){
				char Y = 'A'+MY1-1;
				cout << "2 " << a << " " << X1 << " " << Y << " " << MX1 << " " << b << " " << X2 << endl;
			}else{
				char Y = 'A'+MY2-1;
				cout << "2 " << a << " " << X1 << " " << Y << " " << MX2 << " " << b << " " << X2 << endl;
			}
		}
	}
	return 0;
}


