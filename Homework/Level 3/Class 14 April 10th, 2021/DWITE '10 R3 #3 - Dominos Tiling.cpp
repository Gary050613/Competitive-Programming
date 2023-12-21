#include <bits/stdc++.h>
using namespace std;
const int rem = 1e6;
int N, A[35]={0}, B[35]={0};
int main(){
	int rec = 5;
	A[0]=1, A[1]=0, B[0]=0, B[1]=1;
	for(int i = 2;i<=30;i++){
		A[i] = (A[i-2] + 2*B[i-1])%rem;
		B[i] = (A[i-1] + B[i-2])%rem;
	}
	while(rec--){
		cin >> N;
		cout << A[N] << endl;
	}
	return 0;
}


