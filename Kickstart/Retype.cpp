#include <bits/stdc++.h>
using namespace std;

int main(){

	int t;
	int end, cur, sword;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
    	cin >> end >> cur >> sword;
    	cout << "Case #" << i << ": " << min((end-sword)+(cur-sword)+cur,end+cur) << endl;
    }

	return 0;
}


