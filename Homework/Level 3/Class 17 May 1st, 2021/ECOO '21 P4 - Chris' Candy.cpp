#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K, sum=0; vector<ll> f;
int main(){
	cin >> K; K++;
	for(ll i = 2, up = K; i*i<=up;i++){
		while(K % i == 0){
			f.push_back(i-1); K/=i; sum += i-1;
		}
	}
	if(K != 1) {
		f.push_back(K-1); sum += K-1;
	}
	if(sum > 1e5){
		cout << "Sad Chris\n";
	}else{
		cout << sum << endl;
		for(int i = 0;i<f.size();i++){
			ll num = f[i];
			for(int j = 0;j<num;j++) cout << i+1 << " ";
		}
		cout << endl;
	}
	return 0;
}


