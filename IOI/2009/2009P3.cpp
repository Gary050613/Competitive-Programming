/*
First ever IOI problem solved
*/
#include <bits/stdc++.h>
using namespace std;

struct contestant{
	int ID, score, tasks;
	bool solved[2001];
} rankings[2001];

bool cmp(contestant a, contestant b){
	if(a.score > b.score) return true;
	else if(a.score < b.score) return false;
	else{
		if(a.tasks > b.tasks) return true;
		else if(a.tasks < b.tasks) return false;
		else{
			if(a.ID < b.ID) return true;
			else return false;
		}
	}
}

int main(){
	int N, T, P, q[2001]={0},a;
	cin >> N >> T >> P;
	for(int i = 1;i<=N;i++){
		rankings[i].ID=i;
		rankings[i].tasks=0;
		rankings[i].score=0;
		for(int j = 1;j<=T;j++){
			cin >> a;
			if(!a) q[j]++, rankings[i].solved[j]=0;
			else rankings[i].solved[j]=1, rankings[i].tasks++;
		}
	}
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=T;j++){
			if(rankings[i].solved[j]) rankings[i].score += q[j];
		}
//		cout << rankings[i].ID << " " << rankings[i].score << " " << rankings[i].tasks << endl;
//		for(int j = 1;j<=T;j++){
//			cout << rankings[i].solved[j] << " ";
//		}
//		cout << endl << endl;
	}
	sort(rankings+1, rankings+N+1, cmp);
	for(int i = 1;i<=N;i++){
		if(rankings[i].ID == P){
			cout << rankings[i].score << " " << i << endl;
		}
	}
	return 0;
}


