#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, m, n;
	char ch;
	cin >> N;
	while(N--){                                                                               
		cin >> ch >> m >> n;
		if(ch == 'r'|| ch == 'Q') cout << min(m, n) << endl;
		else if(ch == 'K') cout << ((m+1)/2) * ((n+1)/2) << endl;
		else if(ch == 'k') cout << ((m+1)/2) * ((n+1)/2) + (m/2) * (n/2) << endl;
	}
	return 0;
}


