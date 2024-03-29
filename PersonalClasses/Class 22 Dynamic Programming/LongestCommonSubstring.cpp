/*
	? F[x][y] ?? S[1,2,..x] ? T[1,2,...y] ???????????
	?????? F[|S|][|T|]
	
	????:
		1.S[x] ????????			F[x][y] = F[x-1][y] 
		2.T[y] ???????? 		F[x][y] = F[x][y-1]
		3.S[x] & T[y] ??????? 	F[x][y] = F[x-1][y-1]
	?????????:
		F[x][y] = max{F[x-1][y],F[x][y-1],F[x-1][y-1]+1} ,??? S[x] == T[y]
	????:
		F[0][y] = 0
		F[x][0] = 0
		
	?? F[x][y] ??? F[x-1][y-1] F[x-1][y] F[x][y-1]
		????? F[x][y] ??? 
		????? F[x][y] ??? 
	????? 0 ?,????????,???,????????? 
	
	????? O(|S|*|T|) 
*/
#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
const int MaxN = 5005;
string S,T;
int F[MaxN][MaxN];
int main(){

	cin >> S;
	cin >> T;
	int ls = S.length(),lt = T.length();
	for(int i = 1; i <= ls; i++){
		for(int j = 1 ; j <= lt;j++){
			F[i][j] = max(F[i-1][j],F[i][j-1]);
			if(S[i-1] == T[j-1]){
				F[i][j] = max(F[i][j],F[i-1][j-1] + 1);
			}
		}
	}
	cout << F[ls][lt] << endl;

	return 0;
}
