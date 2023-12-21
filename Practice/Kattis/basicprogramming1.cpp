#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll N, t, A[200001], sum=0, Esum=0, v[200001]={0};
	cin >> N >> t;
	for(ll i = 0;i<N;i++){
		cin >> A[i];
		sum+=A[i];
		if(A[i]%2==0) Esum+=A[i];
	}
	switch(t){
		case 1:
			cout << 7 << endl;
			break;
		case 2:
			if(A[0]>A[1]) cout << "Bigger\n";
			else if(A[0] == A[1]) cout << "Equal\n";
			else cout << "Smaller\n";
			break;
		case 3:
			sort(A, A+3);
			cout << A[1] << endl;
			break;
		case 4:
			cout << sum << endl;
			break;
		case 5:
			cout << Esum << endl;
			break;
		case 6:
			for(ll i = 0;i<N;i++){
				char ch = 'a' + A[i]%26;
				cout << ch;
			}
			cout << endl;
			break;
		case 7:
			ll i = 0;
			while(1){
				if(v[i]){
					cout << "Cyclic\n";
					break;
				}
				v[i]=1;
				i = A[i];
				if(i<0||i>N-1){
					cout << "Out\n";
					break;
				}else if(i == N-1){
					cout << "Done\n";
					break;
				}
			}
			break;
	}
	return 0;
}


