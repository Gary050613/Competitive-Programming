#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

unsigned long long arr[1001];

int main(){

	int n;
	cin >> n;
	arr[0] = 1;
	arr[1] = 0;
	// .
	arr[2] = 1;
	// . .
	// L R
	arr[3] = 2;
	// . . .
	//   L R
	// L   R
	arr[4] = 2;
	// . . . .
	// L R L R
	//   L   R
	arr[5] = 4;
	// . . . . .
	//   L R L R
	// L   R L R
	// L R   L R
	// L R L   R
	arr[6] = ;
	// . . . . . .
	// L R L R L R
	//   L   R L R
	//   L R   L R
	//   L R L   R
	// L   R   l R
	// L   R L   R
	// L R   L   R
	
	for(int i = 3;i<=n;i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	cout << arr[n];
	return 0;
}

