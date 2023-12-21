#include <bits/stdc++.h>
using namespace std;
string hand[6]; int dig[6];

int charToInt(char ch){
	if(ch=='A') return 1;
	else if(ch=='T') return 10;
	else if(ch=='J') return 11;
	else if(ch=='Q') return 12;
	else if(ch=='K') return 13;
	else return ch - '0';
}

int checkRun(){
	int comb[15]={0};
	for(int i = 1;i<=5;i++)
		comb[charToInt(hand[i][0])]++;
	// Straight
	for(int i = 0;i<=12;i++){
		bool out = true;
		for(int j=0;j<5;j++){
			if(!comb[(i+j)%13+1]) out = false;
		}
		if(out) return 100;
	}
	// Invite-the-Neighbours
	for(int i = 0;i<=12;i++){
		bool out = true;
		for(int j=0;j<4;j++){
			if(!comb[(i+j)%13+1]) out = false;
		}
		if(out) return 10;
	}
	// Bed-and-Breakfast
	for(int i = 0;i<=12;i++){
		bool out = true;
		for(int j=0;j<3;j++){
			if(!comb[(i+j)%13+1]) out = false;
		}
		if(out){
			int _comb[15];
			for(int j = 1;j<=13;j++) _comb[j] = comb[j];
			for(int j=0;j<3;j++) _comb[(i+j)%13+1]--;
			for(int a=0;a<=12;a++){
				bool bed = true;
				for(int j=0;j<2;j++) if(!_comb[(a+j)%13+1]) bed = false;
				if(bed) return 5;
			}
		}
	}
	// Menage-a-Trois
	for(int i = 0;i<=12;i++){
		bool out = true;
		for(int j=0;j<3;j++){
			if(!comb[(i+j)%13+1]) out = false;
		}
		if(out) return 3;
	}
	// Double Dutch
	for(int i = 0;i<=12;i++){
		bool out = true;
		for(int j=0;j<2;j++){
			if(!comb[(i+j)%13+1]) out = false;
		}
		if(out){
			int _comb[15];
			for(int j = 1;j<=13;j++) _comb[j] = comb[j];
			for(int j=0;j<2;j++) _comb[(i+j)%13+1]--;
			for(int a=0;a<=12;a++){
				bool bed = true;
				for(int j=0;j<2;j++) if(!_comb[(a+j)%13+1]) bed = false;
				if(bed) return 1;
			}
		}
	}
	return 0;
}

int main(){
	char suit[4]={'S', 'H', 'D', 'C'}, deck[14] = {'0', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
	while(cin >> hand[1] && hand[1] != "#"){
		cin >> hand[2] >> hand[3] >> hand[4] >> hand[5];
		int initial = checkRun()*47;
		int best = initial;
		string exchange;
		map<string, bool> mp;
		for(int i = 1;i<=5;i++) mp[hand[i]] = true;
		for(int a = 1;a<=5;a++){
			int total=0;
			
			for(int j = 0;j<4;j++){
				for(int i = 1;i<=13;i++){
					string c = "";
					c = c + deck[i]+suit[j];
					if(mp[c]) continue;
					string tmp = hand[a];
					hand[a] = c;
					total+=checkRun();
					hand[a] = tmp;
				}
			}
			total -= 47;
			if(total > best){
				best = total;
				exchange = hand[a];
			}
		}
		if(best > initial){
			cout << "Exchange " << exchange << endl;
		}else{
			cout << "Stay\n";
		}
	}
	return 0;
}


