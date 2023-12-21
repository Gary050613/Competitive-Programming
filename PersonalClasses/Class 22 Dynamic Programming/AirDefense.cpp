#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int used[1001], arr[1001][2], n = 0, ans1 = 0, ans2 = 1;
	memset(used,9999,sizeof(used));
	while(cin >> arr[n++][0]){
//		cout << n-1 << " " << arr[n-1][0] << endl;
		for(int i = 0;i<ans2;i++){
			if(used[i] > arr[n-1][0]){
				used[i] = arr[n-1][0];
				break;
			}
			if(i == ans2-1){
				used[ans2] = arr[n-1][0];
				ans2++;
				break;
			}
		}
		sort(used,used+ans2);
	}
	cout << n << endl;
	for(int i = 0;i<n-1;i++){
		int m = 0;
		for(int j = 0;j<i;j++){
			if(arr[j][1] > m && arr[j][0] > arr[i][0]){
				m = arr[j][1];
			}
		}
		arr[i][1] = m+1;
		ans1 = max(ans1, m+1);
	}
	cout << ans1 << endl << ans2 << endl;
	return 0;
}

/*
389 207 155 300 299 170 158 65
*/
