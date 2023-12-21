#include <bits/stdc++.h>
using namespace std;
int maxarr[200005], minarr[200005];
int main(){
	int T;
	cin >> T;
	while(T--){
		int n, curM=0, a, maxcur, mincur=1;
//		memset(arr, 0, sizeof(arr));
		cin >> n;
		bool maxused[n+1]={0}, minused[n+1]={0};
		for(int i = 1;i<=n;i++){
			cin >> a;
			if(a > curM){
				maxarr[i]=a;
				minarr[i]=a;
				maxused[a]=1;
				minused[a]=1;
				curM = a;
				maxcur=curM-1;
			}else{
				for(int j = maxcur;j>=1;j--){
					if(!maxused[j]){
						maxarr[i] = j;
						maxused[j]=1;
						maxcur=j-1;
						break;
					}
				}
				for(int j = mincur;j<=curM;j++){
					if(!minused[j]){
						minarr[i] = j;
						minused[j]=1;
						mincur = j+1;
						break;
					}
				}
			}
		}
		for(int i = 1;i<=n;i++){
			cout << minarr[i] << " ";
		}
		cout << endl;
		for(int i = 1;i<=n;i++){
			cout << maxarr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}


