#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int triangle[3001][3001];

int main(){
	
	ifstream cin ("s5.2-03.in");
	int size, subsize;
	cin >> size >> subsize;
//	int triangle[size][size];
	for(int i = 0;i<size;i++){
		for(int j = 0;j<=i;j++){
			cin >> triangle[i][j];
		}
	}
	for(int k = 1;k<subsize;k++){
		for(int i = size-1;i>=k;i--){
			for(int j = 0;j<=i;j++){
				triangle[i][j] = max(max(triangle[i][j], triangle[i-1][j]), triangle[i][j+1]);
			}
		}
	}
	ll ans = 0;
	for(int i = subsize-1;i<size;i++){
		for(int j = 0;j<=i-subsize+1;j++){
//			cout << triangle[i][j] << " ";
			ans += triangle[i][j];
		}
//		cout << endl;
	}
	cin.close();
	cout << ans << endl;

	return 0;
}


