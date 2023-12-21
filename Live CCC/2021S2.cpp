#include <bits/stdc++.h>
using namespace std;
bool rows[5000001]={0}, col[5000001]={0};
int main(){
	
	int M, N, K, n, ans = 0;
	char ch;
	cin >> M >> N >> K;
	while(K--){
		cin >> ch >> n;
		if(ch == 'R'){
			if(rows[n] == 0){
				rows[n] = 1;
			}else{
				rows[n] = 0;
			}
		}else{
			if(col[n] == 0){
				col[n] = 1;
			}else{
				col[n] = 0;
			}
		}
	}
//	for(int i = 1;i<=M;i++){
//		cout << rows[i] << " ";
//	}
//	cout << endl;
//	for(int i = 1;i<=N;i++){
//		cout << col[i] << " ";
//	}
//	cout << endl;
	for(int i = 1;i<=M;i++){
		for(int j = 1;j<=N;j++){
			if((rows[i]==1 && col[j]==0) || (rows[i]==0 && col[j]==1)){
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}


