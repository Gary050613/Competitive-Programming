#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, a, div=0, sum=0;
	cin >> n;
	while(n--){
		cin >> a;
		if(a == -1){
			continue;
		}
		div++;
		sum+=a;
	}
	printf("%.20lf\n", (double)sum/(double)div);
	return 0;
}


