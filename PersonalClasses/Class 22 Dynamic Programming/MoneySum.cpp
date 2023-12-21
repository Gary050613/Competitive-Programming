#include<iostream>
using namespace std;
int coinNum[1001];
int coinVal[1001];
int coin[] = {1,7,10};
void Find(int money,int n){
	for(int i = 1 ; i <= money; i++){
		int Min = i;
		int used = 0;
		for(int j = 0 ; j < n;j++){
			if(i >= coin[j]){
				if(coinNum[i - coin[j]] + 1 <= Min){
					Min = coinNum[i - coin[j]] + 1;
					used = coin[j];
				}
			}
		}
		coinNum[i] = Min;
		coinVal[i] = used;
	}
	if(coinVal[money] == 0){
		cout << "???" << endl;
	}
	else{
		cout << coinNum[money] << endl;
	}
	while(money > 0){
		cout << coinVal[money] << " ";
		money -= coinVal[money];
	}
}
int main(){
	
	int Money = 0;
	cin >> Money;
	Find(Money,3);

	return 0;
}
