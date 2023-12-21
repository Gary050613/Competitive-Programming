#include <bits/stdc++.h>
using namespace std;
int X[10005], Y[100005];
bool Ahas[100005]={0}, Bhas[100005]={0};
int main(){
	int A, B;
	while(cin >> A >> B && (A||B)){
		memset(Ahas, 0, sizeof(Ahas));
		memset(Bhas, 0, sizeof(Bhas));
		for(int i = 0;i<A;i++){
			cin >> X[i];
			Ahas[X[i]]=1;
		}
		for(int i = 0;i<B;i++){
			cin >> Y[i];
			Bhas[Y[i]]=1;
		}
		int Agive=0, Bgive=0;
		for(int i=0;i<A;i++){
			if(!Bhas[X[i]]){
				Bhas[X[i]]=1;
				Agive++;
			}
		}
		for(int i=0;i<B;i++){
			if(!Ahas[Y[i]]){
				Ahas[Y[i]]=1;
				Bgive++;
			}
		}
		cout << min(Agive, Bgive) << endl;
	}
	return 0;
}


