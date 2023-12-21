#include <bits/stdc++.h>
using namespace std;
char arr[9] = {'!','@','#','$','%','^','&','*','('};
char g[11][11];
int main(){
	int N, n;
	cin >> N;
	while(N--){
		cin >> n;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				cin >> g[i][j];
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(g[i][j] == '.'){
					for(int ch = 0;ch<9;ch++){
						bool ok = true;
						if(i>1 && g[i-1][j] == arr[ch]) ok = false;
						if(j>1 && g[i][j-1] == arr[ch]) ok = false;
						if(i<n-1 && g[i+1][j] == arr[ch]) ok = false;
						if(j<n-1 && g[i][j+1] == arr[ch]) ok = false;
						if(ok){
							g[i][j] = arr[ch];
							break;
						}
					}
				}
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				cout << g[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}


