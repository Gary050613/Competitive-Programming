#include <bits/stdc++.h>
using namespace std;

int main(){
	int round, guesses=0;
	bool guessed[30]={0}, correct[101]={0};
	string ans, seq;
	while(cin >> round && round != -1){
		memset(guessed, 0, sizeof(guessed));
		memset(correct, 0, sizeof(correct));
		cin >> ans >> seq;
		guesses=0;
		int final=0;
		for(int i = 0;i<seq.length();i++){
			int flag=0;
			for(int j = 0;j<ans.length();j++){
				if(seq[i]==ans[j]){
					flag=1;
					correct[j]=1;
				} 
			}
			if(!guessed[seq[i]-'a']&&!flag) guesses++;
			guessed[seq[i]-'a']=1;
			flag=1;
			for(int j = 0;j<ans.length();j++){
//				cout << correct[j] << ' ';
				if(!correct[j]) flag=0;
			}
//			cout << endl;
			if(flag){
				final=1;
				break;
			}
			if(guesses>=7){
				final=-1;
				break;
			}
		}
		printf("Round %d\n", round);
		if(final==1) cout << "You win.\n";
		else if(final==-1) cout << "You lose.\n";
		else cout << "You chickened out.\n";
	}
	return 0;
}


