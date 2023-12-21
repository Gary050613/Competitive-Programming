#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int lenS, lenT, ans = 0;
	string s, T;
	scanf("%d %d", &lenS, &lenT);
	cin >> s >> T;
	for(int i = 0;i<lenT;i++){
		int counter = ans;
		while(T[i] != s[ans%lenS]){
			if(ans - counter > lenT){
				ans = -1;
				i = lenT;
				break;
			}
			ans++;
		}
		ans++;
	}
	if(ans == 0){
		printf("-1");
	}else{
		printf("%d", ans);
	}
	return 0;
}


