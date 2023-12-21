	#include <bits/stdc++.h>
	using namespace std;
	
	int getValue(char ch){
		if(ch == 'A'||ch=='J'||ch=='K'||ch=='Q'||ch=='T'){
			return 10;
		}else{
			return ch-48;
		}
	}
	
	int main(){
		int T;
		cin >> T;
		for(int cnt = 1;cnt<=T;cnt++){
			string str, pile[60];
			for(int i = 1;i<=52;i++){
				cin >> pile[i];
			}
			int cur=27, Y=0, X=0;
			for(int i = 0;i<3;i++){
				X = getValue(pile[cur][0]);
				Y+=X;
				cur--;
				cur-=10-X;
			}
	//		cout << Y << " ";
			if(Y<=cur){
				printf("Case %d: ", cnt);
				cout << pile[Y] << endl;
			}else{
				printf("Case %d: ", cnt);
				cout << pile[Y-cur+27] << endl;
			}
		}
		return 0;
	}
	

