#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans = 0; int R, T; string A, S; char C, first, last; unordered_map<char, string> mp; unordered_map<char, ll> mm1, mm2;
int main(){
	for(int i=0;i<10;i++){
		cin >> R >> T >> A;
		mm1.clear(), mm2.clear(), mp.clear();
		ans = 0;
		for(char j : A) mm1[j]++;
		for(int j=0;j<R;j++){
			cin >> C >> S;
			mp[C] = S;
		}
		first = A[0];
		last = A[A.length()-1];
		for(int j=0;j<T;j++){
			first = mp[first][0];
			last = mp[last][mp[last].length()-1];
			for(auto k:mm1)
				for(auto ch:mp[k.first])
					mm2[ch] += k.second;
			mm1 = mm2;
			mm2.clear();
		}
		for(auto j:mm1) ans += j.second;
		cout << first << last << " " << ans << endl;
	}
	return 0;
}


