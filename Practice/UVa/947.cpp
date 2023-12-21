#include <bits/stdc++.h>
using namespace std;
int correct, wrong, ans=0;
char answer[6], guess[6];
void solve(int n, int ci){
	if(ci == n){
		int x=0, y=0;
		char s[6], t[6];
		memcpy(s, answer, n);
		memcpy(t, guess, n);
		for(int i = 0;i<n;i++){
			if(s[i] == t[i]){
				s[i] = t[i] = '0';
				x++;
			}
		}
		for(int i = 0;i<n;i++){
			if(s[i] != '0'){
				for(int j = 0;j<n;j++){
					if(s[i]==t[j]){
						s[i] = t[j] = '0';
						y++;
						break;
					}
				}
			}
		}
	//	cout << guess << ' ' << x << " " << y << endl;
	//	if(x == correct && y == wrong){
	//		cout << guess << " ";
	//	}
		if(x == correct && y == wrong) ans++;
	}else{
		for(int i = 1;i<=9;i++){
			guess[ci] = '0'+i;
			solve(n, ci+1);
		}
	}
}

int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> answer >> correct >> wrong;
		ans=0;
		solve(strlen(answer), 0);
		cout << ans << endl;
	}
	return 0;
}


