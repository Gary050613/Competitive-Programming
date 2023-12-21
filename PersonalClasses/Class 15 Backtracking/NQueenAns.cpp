#include<iostream>
using namespace std;
const int N = 20;
bool C[N+1],D[2*N],E[2*N+1];
int n,ans = 0;
void queen(int x){
	if(x == n+1){
		ans++;
		return;
	}
	for(int j = 1; j <= n; j++){
		if(!C[j] && !D[x-j+N] && !E[x+j]){
			C[j] = D[x-j+N] = E[x+j] = true;
			queen(x+1);
			C[j] = D[x-j+N] = E[x+j] = false;
		}
	}
}
int main(){

	cin >> n;
	queen(1);
	cout << ans << endl;
	

	return 0;
}
