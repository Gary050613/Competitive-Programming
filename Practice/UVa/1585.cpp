#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	char str[81];
	cin >> n;
	while(n--){
		cin >> str;
		int ans = 0, cnt = 0;
		for(int i = 0;i<strlen(str);i++){
			if(str[i] == 'O'){
				cnt++;
				ans+=cnt;
			}else{
				cnt = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}


