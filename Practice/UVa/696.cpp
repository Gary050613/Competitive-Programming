#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M;
	while(cin >> N >> M && (N||M)){
		if(N>=3&&M>=3){
			cout << ((N+1)/2)*((M+1)/2)+(N/2)*(M/2) << " knights may be placed on a " << N << " row " << M << " column board.\n";
		}else if(N==1){
			cout << M << " knights may be placed on a " << N << " row " << M << " column board.\n";
		}else if(M==1){
			cout << N << " knights may be placed on a " << N << " row " << M << " column board.\n";
		}else if(N==2){
			if(M%4 <= 2){
				cout << max(M, ((M)/4)*4+(M%4)*2) << " knights may be placed on a " << N << " row " << M << " column board.\n";
			}else{
				cout << max(M, ((M+2)/4)*4) << " knights may be placed on a " << N << " row " << M << " column board.\n";
			}
		}else if(M==2){
			if(N%4 <= 2){
				cout << max(N, ((N)/4)*4+(N%4)*2) << " knights may be placed on a " << N << " row " << M << " column board.\n";
			}else{
				cout << max(N, ((N+2)/4)*4) << " knights may be placed on a " << N << " row " << M << " column board.\n";
			}
		}
	}
	return 0;
}


