#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans = 1;
int letters[27] = {0};
string S;
int main(){
	
	cin >> S;
	for(int i = 0;i<S.length();i++){
		letters[S[i]-'a']++;
	}
	for(int i = 0;i<27;i++){
//		cout << letters[i] << " ";
		ans = (ans % 1000000007) * (letters[i]+1);
	}
	ans %= 1000000007;
	cout << ans << endl;
	
	return 0;
}


