#include <bits/stdc++.h>
using namespace std;
double p, a, b, c, d, n, previous=0;
double price(double k){
	return p*(sin(a*k+b)+cos(c*k+d)+2);
}

int main(){
	cin >> p >> a >> b >> c >> d >> n;
	double ans = 0;
	for(double i = 1;i<=n;i++){
		if(previous > price(i)){
			ans = max(ans, previous-price(i));
		}else{
			previous = price(i);
		}
	}
	printf("%.7f\n", ans);
	return 0;
}


