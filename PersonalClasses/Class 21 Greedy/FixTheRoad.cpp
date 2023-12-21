#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, road[101], ans = 0;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> road[i];
	}
	for(int i = 1;i<=n-1;i++){
		if(road[i] > road[i+1]){
			ans += road[i]-road[i+1];
		}else{
			ans += road[i];
		}
	}
	cout << ans << endl;
	
	return 0;
}


