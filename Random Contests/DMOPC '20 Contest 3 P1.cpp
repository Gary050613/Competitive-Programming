#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, a;
	bool ans = 0;
	cin >> n;
	int f[n+1]={0};
	for(int i = 1;i<=n;i++){
		cin >> a;
		f[a]++;
		if(f[a] > 1){
			ans = 1;
		}
	}
	if(ans){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}
	
	return 0;
}


