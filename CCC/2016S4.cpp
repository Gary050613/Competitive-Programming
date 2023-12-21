//#include <bits/stdc++.h>
//using namespace std;
//int f[401][401];
//int main(){
//	
//	int n, a, r[401], ans = 0;
//	scanf("%d", &n);
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			f[i][j] = 0;
//		}
//	}
//	for(int i = 1;i<=n;i++){
//		scanf("%d", &a);
//		r[i] = r[i-1] + a;
//		f[i][i] = a;
//	}
//	for(int i = n-1;i>=1;i--){
//		for(int j = i+1;j<=n;j++){
//			for(int k = i;k<=j-1;k++){
//				if(f[i][k] == f[k+1][j]){
//					f[i][j] = max(f[i][j], f[i][k] + f[k+1][j]);
//					ans = max(ans, f[i][j]);
//				}
//			}
//			for(int k = i;k<=j-2;k++){
//				for(int p = k+1;p<=j-1;p++){
//					if(f[i][k] == f[p][j] && f[k+1][p-1]){
//						f[i][j] = max(f[i][j], f[i][k] + f[p][j] + f[k+1][p-1]);
//						ans = max(ans, f[i][j]);
//					}
//				}
//			}
//		}
//	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			cout << f[i][j] << " ";
//		}
//		cout << endl;
//	}
//	printf("%d", ans);
//	
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;

int n, f[500][500], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i][i];
        ans = max(ans, f[i][i]);
    }

    for (int len = 2; len <= n; ++len) {
        for (int l = 1, r = len; r <= n; ++l, ++r) {
            // ????
            for (int k = l; k < r; ++k) {
                if (f[l][k] && f[k + 1][r] && f[l][k] == f[k + 1][r]) {
                    f[l][r] = f[l][k] + f[k + 1][r];
                    break;
                }
            }

            // ???,????
            for (int k = l, t = r; k < t - 1; ) {
                if (f[l][r]) break;
                if (!f[l][k]) ++k;
                else if (!f[t][r]) --t;
                else if (f[l][k] == f[t][r]) {
                    if (f[k + 1][t - 1])
                        f[l][r] = f[l][k] + f[k + 1][t - 1] + f[t][r];
                    else ++k, --t;
                }
                else if (f[l][k] < f[t][r]) ++k;
                else if (f[l][k] > f[t][r]) --t;
            }
            ans = max(ans, f[l][r]);
        }
    }

    cout << ans << endl;
    return 0;
}
