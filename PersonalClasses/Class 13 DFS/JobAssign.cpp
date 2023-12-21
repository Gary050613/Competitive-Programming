#include<iostream>
using namespace std;
int maxl = 0,g[27],f[27],n;
int data[27][27];
bool p[27] = {0};
//step store which person,t store total profit
int go(int step,int t){
	for(int i = 1; i <= n;i++){
		//If i is selected
		if(!p[i]){
			//step person select
			f[step] = i;
			//Mark the job as selected 
			p[i] = 1;
			//Job efficiency/ Profit
			t += data[step][i];
			if(step < n){
				go(step+1,t);
			}
			//Storing maximum profit
			else if(t > maxl){
				maxl = t;
				for(int j = 1; j <= n; j++){
					//Storing maximum profit job plan
					g[j] = f[j];
				}
			}
			//If possible go deeper, or else go back
			t -= data[step][i];
			p[i] = 0;
		}
	}
}
int main(){

	cin >> n;
	for(int i = 1; i <= n;i++){
		for(int j = 1; j<= n; j++){
			cin >> data[i][j];
		}
	}
	go(1,0);
	for(int i = 1; i <= n; i++){
		cout << char(64+i) << ":J" << g[i] << " ";
	}
	cout << endl;
	cout << "Total Profit:" << maxl << endl; 

	return 0;
}
