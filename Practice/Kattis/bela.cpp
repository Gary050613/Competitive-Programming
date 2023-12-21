#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, ans=0;
	char B;
	string card;
	cin >> N >> B;
	map<char, int> dom, notdom;
	dom['A']=11, notdom['A']=11;
	dom['K']=4, notdom['K']=4;
	dom['Q']=3, notdom['Q']=3;
	dom['J']=20, notdom['J']=2;
	dom['T']=10, notdom['T']=10;
	dom['9']=14, notdom['9']=0;
	dom['8']=0, notdom['8']=0;
	dom['7']=0, notdom['7']=0;
	N*=4;
	while(N--){
		cin >> card;
		if(card[1]==B){
			ans += dom[card[0]];
		}else{
			ans += notdom[card[0]];
		}
	}
	cout << ans << endl;
	return 0;
}


