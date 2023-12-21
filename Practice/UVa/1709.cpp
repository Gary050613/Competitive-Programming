#include <bits/stdc++.h>
using namespace std;
double p, a, b, c, d, n, previous=0;
double price(double k){
	return p*(sin(a*k+b)+cos(c*k+d)+2);
}

int main(){
	while(scanf("%lf %lf %lf %lf %lf %lf", &p, &a, &b, &c, &d, &n)!=EOF){
		double ans = 0;
		previous = price(1);
		for(double i = 2;i<=n;i++){
			double cur = price(i);
			if(previous > cur){
				ans = max(ans, previous-cur);
			}else{
				previous = cur;
			}
		}
		printf("%.8lf\n", ans);
	}
	
	return 0;
}


