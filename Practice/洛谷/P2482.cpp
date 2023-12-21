#include <bits/stdc++.h>
using namespace std;
vector<int> hand[11];
string identity[11];
char deck[2001];
int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0;i<n;i++){
		scanf("%s", &identity[i]);
		for(int j = 0;j<4;j++){
			char ch;
			scanf("%c", &ch);
			hand[i].push_back(ch);
		}
	}
	deck[0] = 1;
	for(int i = 1;i<=m;i++){
		scanf("%c", &deck[i]);
	}
	
	return 0;
}


