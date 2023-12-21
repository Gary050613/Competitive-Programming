#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, a, b, ans = 1;
	int m[101];
	cin >> n;
	while(n--){
		cin >> a >> b;
		for(int i = 1;i<=a;i++){
			cin >> m[i];
		}
		for(int i = 1;i<=b;i++){
			ans = -1;
			for(int j = 1;j<=a-1;j++){
				if(m[j+1] > m[j]){
					ans = j;
					break;
				}
			}
			if(ans == -1) break;
			m[ans]++;
		}
		cout << ans << "\n";
	}
	
	return 0;
}


