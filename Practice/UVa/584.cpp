#include <bits/stdc++.h>
using namespace std;
string str; char ch; int score=0, bonus[50]={0}, c = 0, pre=0;
int main(){
	while(getline(cin, str) && str != "Game Over"){
		score = 0, pre = 0, c=0;
		for(int i=0;i<50;i++) bonus[i] = 1;
//		for(int i : bonus) cout << i << " ";
		for(int i = 0;i<str.length();i+=2){
			if(str[i] == 'X'){
				c+=2;
				if(c < 20) bonus[i+2]++, bonus[i+4]++;
				score+=10*bonus[i];
				pre = 10;
			}else if(str[i] == '/'){
				c++;
				if(c < 20) bonus[i+2]++;
				score+=(10-pre)*bonus[i];
				pre = 10-pre;
			}else{
				score+=(str[i]-'0')*bonus[i];
				pre = str[i]-'0';
				c++;
			}
//			cout << c << " ";
		}
//		cout << endl;
//		for(int i=0;i <= 24;i+=2){
//			cout << bonus[i] << " ";
//		}
		cout << score << endl;
	}
	return 0;
}


