#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, n, ans, total, vote, a;
	cin >> T;
	while(T--){
		cin >> n;
		ans=0, total=0,vote=0;
		for(int i = 1;i<=n;i++){
			cin >> a;
			if(a > vote){
				vote = a;
				ans = i;
			}else if(a==vote){
				ans = 0;
			}
			total+=a;
		}
		if(ans == 0){
			cout << "no winner\n";
		}else if(vote > total/2){
			cout << "majority winner " << ans << endl;
		}else{
			cout << "minority winner " << ans << endl;
		}
	}
	return 0;
}


