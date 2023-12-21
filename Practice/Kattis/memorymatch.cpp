#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, K, ans=0, a, b, known=0, used=0, doubles=0, Csize=0, unknown=0;
	string cardA, cardB, cards[1001];
	cin >> N >> K;
	Csize = N;
	for(int i = 1;i<=N;i++){
		cards[i] = "Unknown";
	}
	while(K--){
		cin >> a >> b >> cardA >> cardB;
		cards[a]=cardA;
		cards[b]=cardB;
		if(cardA == cardB){
			cards[a] = "CHOSEN";
			cards[b] = "CHOSEN";
			Csize-=2;
		}
	}
	for(int i = 1;i<=N;i++){
		if(cards[i]=="Unknown"){
			unknown++;
			continue;
		}
		if(cards[i]=="CHOSEN") continue;
//		cout << cards[i] << " ";
		for(int j = 1;j<=N;j++){
			if(i==j) continue;
			if(cards[i]==cards[j]) doubles++;
		}
	}
	known = Csize-doubles-unknown;
	ans = doubles/2;
	if(known >= unknown){
		ans += known;
	}else if(unknown == 2){
		ans++;
	}
	cout << ans << endl;
	return 0;
}


