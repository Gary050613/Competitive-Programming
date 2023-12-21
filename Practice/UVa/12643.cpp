#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, i, j, ans=0;
	while(cin >> N >> i >> j){
		ans=0;
		while(i!=j){
			i = (i+1)/2;
			j = (j+1)/2;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}


