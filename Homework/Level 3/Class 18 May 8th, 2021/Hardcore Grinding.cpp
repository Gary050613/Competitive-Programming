#include <bits/stdc++.h>
using namespace std;
const int MM = 1e7+5;
int N, s, f, diff[MM],ans=0, cur = 0, m = 0;
int main(){
	cin >> N;
	memset(diff, 0, sizeof(diff));
	for(int i = 0;i<N;i++){
		cin >> s >> f;
		diff[s]++, diff[f]--;
		m = max(m, f);
	}
	for(int i = 1;i<=m;i++){
		cur += diff[i];
		ans = max(cur, ans);
	}
	cout << ans << endl;
	return 0;
}


