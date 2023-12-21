#include <bits/stdc++.h>
using namespace std;
int G, P, docked[100001], ans = 0;

int main(){
	
	cin >> G >> P;
	memset(docked, 0, sizeof(docked));
	int p;
	for(int i = 1;i<=P;i++){
		if(i > G){
			break;
		}
		cin >> p;
		for(int j = p;j>=1;j--){
			if(!docked[j]){
				docked[j] = 1;
				ans++;
				j = 0;
				continue;
			}
			if(j == 1){
				i = P+1;
				break;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}


