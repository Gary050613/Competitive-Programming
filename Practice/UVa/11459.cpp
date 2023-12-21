#include <bits/stdc++.h>
using namespace std;
int pos[1000005];
int main(){
	int T, a, b, c;
//	scanf("%d", &T);
	cin >> T;
	while(T--){
		memset(pos, 0, sizeof(pos));
		unordered_map<int, int> mp;
		cin >> a >> b >> c;
		int from, to, die, cur=1, flag=0;
		for(int i = 1;i<=a;i++){
			pos[i] = 1;
		}
		while(b--){
			cin >> from >> to;
			mp[from] = to;
		}
//		for(auto i : mp){
//			cout << i.first << " " << i.second << endl;
//		}
		while(c--){
			if(flag){
				cin >> die;
				continue;
			}
			if(cur > a) cur = 1;
			cin >> die;
			pos[cur]+=die;
			if(mp[pos[cur]]) pos[cur] = mp[pos[cur]];
			if(pos[cur]>=100){
				flag=1;
			}
			cur++;
		}
		for(int i = 1;i<=a;i++){
			printf("Position of player %d is %d.\n", i, pos[i]);
		}
	}
	return 0;
}


