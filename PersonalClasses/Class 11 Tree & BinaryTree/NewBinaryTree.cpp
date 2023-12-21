#include <bits/stdc++.h>
#define maxn 10001
using namespace std;

struct tree{
	int parent;
	int lc, rc;
} a[maxn];

void pre(int root){
	if(root != 0){
		cout << char(root-1+'a');
		pre(a[root].lc);
		pre(a[root].rc);
	}
}

int main(){

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		char ch1,ch2,ch3;
		cin >> ch1>>ch2>>ch3;
		if(ch2 != '*'){
			a[ch2-'a'+1].parent = ch1-'a'+1;
			a[ch1-'a'+1].lc = ch2-'a'+1;
		}
		if(ch3 != '*'){
			a[ch3-'a'+1].parent = ch1-'a'+1;
			a[ch1-'a'+1].rc = ch3-'a'+1;
		}
	}
	int root;
	//????? 
	for(int i = 1;i<=n;i++){
		if(a[i].parent == 0){
			root = i;
			break;
		}
	}
	pre(root);
	cout << endl;

	return 0;
}
