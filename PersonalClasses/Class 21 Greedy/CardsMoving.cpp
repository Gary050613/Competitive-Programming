#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, cards[101], ans = 0, sum = 0;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> cards[i];
		sum += cards[i];
	}
	int avg = sum/n;
	for(int i = 0;i<n;i++){
		cards[i]-=avg;
	}
	for(int i = 0;i<n;i++){
		if(cards[i] == 0){
			continue;
		}else if(cards[i] < 0){
			for(int j = 0;j<n;j++){
				if(i == j){
					continue;
				}
				if(cards[j] > 0){
					if(abs(cards[i]) == cards[j]){
						ans++;
						cards[i] = cards[j] = 0;
						j = n;
					}else if(abs(cards[i]) > cards[j]){
						ans++;
						cards[i] += cards[j];
						cards[j] = 0;
					}else{
						ans++;
						cards[j] += cards[i];
						cards[i] = 0;
					}
				}
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}


