#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000001;
int N, W, D, seq[200001]={0}, Wdis[200001]={maxn}, Tdis[200001]={maxn}, WtoN[200001]={maxn}, TtoN[200001]={maxn}, u[200001]={0}, v[200001]={0}, a, b;

void update(){
	int n;
	for(int i = 1;i<=N;i++){
		if(seq[i] == N){
			n = i;
			break;
		}
	}
	for(int i = 1;i<=n;i++){
		TtoN[seq[i]] = n-i;
	}
	for(int i = n+1;i<=N;i++){
		TtoN[seq[i]] = maxn;
	}
	for(int i = 1;i<=N;i++){
		Tdis[seq[i]] = i-1;
	}
}

int main(){
	
	cin >> N >> W >> D;
	for(int i = 1;i<=N;i++){
		Wdis[i] = maxn;
		Tdis[i] = maxn;
		WtoN[i] = maxn;
		TtoN[i] = maxn;
	}
	for(int i = 1;i<=W;i++){
		cin >> a >> b;
		u[i] = a;
		v[i] = b;
	}
	Wdis[1] = 0;
	WtoN[N] = 0;
	for(int i = 1;i<=W;i++){
		for(int j = 1;j<=W;j++){
			Wdis[v[j]] = min(Wdis[v[j]], Wdis[u[j]]+1);
			WtoN[u[j]] = min(WtoN[u[j]], WtoN[v[j]]+1);
		}
	}
	for(int i = 1;i<=N;i++){
		cin >> seq[i];
	}
	while(D--){
		int ans = maxn;
		cin >> a >> b;
		swap(seq[a], seq[b]);
		update();
//		cout << "Wdis: ";
//		for(int i = 1;i<=N;i++){
//			cout << Wdis[i] << " ";
//		}
//		cout << endl << "Tdis: ";
//		for(int i = 1;i<=N;i++){
//			cout << Tdis[i] << " ";
//		}
//		cout << endl << "WtoN: ";
//		for(int i = 1;i<=N;i++){
//			cout << WtoN[i] << " ";
//		}
//		cout << endl << "TtoN: ";
//		for(int i = 1;i<=N;i++){
//			cout << TtoN[i] << " ";
//		}
//		
//		cout << endl;
		ans = min(ans, WtoN[1]);
		ans = min(ans, TtoN[1]);
		for(int i = 1;i<=N;i++){
			ans = min(ans, Tdis[i] + WtoN[i]);
		}
		cout << ans << endl;
	}
	
	return 0;
}


