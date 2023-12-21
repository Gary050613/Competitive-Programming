#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	if(M - N == 1){
		printf("Dr. Chaz will have 1 piece of chicken left over!\n");
	}else if(N - M == 1){
		printf("Dr. Chaz needs 1 more piece of chicken!\n");
	}else if(M > N){
		printf("Dr. Chaz will have %d pieces of chicken left over!\n", M-N);
	}else if(N > M){
		printf("Dr. Chaz needs %d more pieces of chicken!\n", N-M);
	}
	return 0;
}


