#include<iostream>
using namespace std;
struct data{
	int t,x;
};
const int MAXX = 100001,MAXK = 300001;
data a[MAXK];
int num[MAXX];
int main(){

	int t,k,x,n,ans = 0,p = 0,q = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t >> k;
		for(int j = 0; j < k; j++){
			cin >> x;
			a[q].t = t;
			a[q].x = x;
			q++;
			num[x]++;
			if(num[x] == 1){
				ans++;
			}
		}
		while(a[p].t <= t- 86400){
			num[a[p].x]--;
			if(num[a[p].x] == 0){
				ans--;
			}
			p++;
		}
		cout << ans << endl;
	}

	return 0;
}
