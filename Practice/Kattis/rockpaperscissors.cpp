#include <bits/stdc++.h>
using namespace std;
int n, k, p1, p2; double wins[101], losses[101]; string m1, m2; bool first=1;
int main(){
	while(cin >> n && n){
		if(!first) cout << endl;
		first = 0;
		memset(wins, 0, sizeof(wins));
		memset(losses, 0, sizeof(losses));
		cin >> k;
		for(int a = 0;a<k*n*(n-1)/2;a++){
			cin >> p1 >> m1 >> p2 >> m2;
			if(m1 == "rock"){
				if(m2 == "scissors") wins[p1]++, losses[p2]++;
				else if(m2 == "paper") wins[p2]++, losses[p1]++;
			}else if(m1 == "paper"){
				if(m2 == "rock") wins[p1]++, losses[p2]++;
				else if(m2 == "scissors") wins[p2]++, losses[p1]++;
			}else if(m1 == "scissors"){
				if(m2 == "paper") wins[p1]++, losses[p2]++;
				else if(m2 == "rock") wins[p2]++, losses[p1]++;
			}
		}
		for(int i = 1;i<=n;i++){
			if(!(wins[i]+losses[i])) cout << "-\n";
			else printf("%.3lf\n", wins[i]/(wins[i]+losses[i]));
		}
			
	}
	return 0;
}


