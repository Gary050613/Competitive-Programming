#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, K, cnt=1;
	char str[200001];
	cin >> T;
	while(T--){
		cin >> N >> K >> str;
		int ans = 0;
		for(int i = 0;i<N/2;i++){
			if(str[i] != str[N-i-1]){
				ans++;
			}
		}
		ans = abs(ans-K);
		printf("Case #%d: %d\n", cnt++, ans);
	}
	return 0;
}


