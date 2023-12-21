#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int n, k, ans=0, cur=0, last=0;
		string str;
		cin >> n >> k >> str;
		for(int i = 0;i<n;i++){
			if(str[i] == '*'){
				cur = i;
				ans++;
				break;
			}
		}
		for(int i = n-1;i>=0;i--){
			if(str[i] == '*'){
				last = i;
				ans++;
				break;
			}
		}
		if(cur == last){
			cout << 1 << endl;
			continue;
		}
		while(cur < last){
			if(cur+k>=last){
				break;
			}
			for(int i = cur+k;i>cur;i--){
				if(str[i]=='*'){
					ans++;
					cur = i;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}


