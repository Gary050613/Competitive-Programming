#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	int tides[n];
	for(int i = 0;i<n;i++){
		cin >> tides[i];
	}
	sort(tides, tides+n);
	int mid = (n+1)/2-1;
	int i = mid, j = mid + 1;
	while(i != -1 || j != n){
		cout << tides[i--] << " ";
		if(j != n){
			cout << tides[j++] << " ";
		}
	}
	return 0;
}


