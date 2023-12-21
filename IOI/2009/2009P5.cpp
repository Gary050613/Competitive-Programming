#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M, rate[101]={0}, w[2001]={0}, a, ans=0, cnt=0;
	queue<int> q;
	int parked[2001]={0}, available[101]={0};
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		available[i]=1;
		cin >> rate[i];
	}
	for(int i=1;i<=M;i++){
		cin >> w[i];
	}
	for(int i=1;i<=2*M;i++){
		cin >> a;
		if(a<0){
//			cout << "OUT\n";
			a*=-1;
			available[parked[a]]=1;
			parked[a]=0;
			cnt--;
			if(cnt<N && !q.empty()){
				for(int i=1;i<=N;i++){
					if(available[i]){
						available[i]=0;
						parked[q.front()]=i;
						ans+=w[q.front()]*rate[i];
						cnt++;
						q.pop();
						break;
					}
				}
			}
		}else{
//			cout << "IN\n";
			if(cnt >= N){
//				cout << "QUEUED\n";
				q.push(a);
			}else{
				for(int i=1;i<=N;i++){
					if(available[i]){
//						cout << "AVAILABLE AT " << i << "\n";
						available[i]=0;
						parked[a]=i;
						ans+=w[a]*rate[i];
//						cout << ans << endl;
						cnt++;
						break;
					}
				}
			}
			
		}
	}
//	for(int i = 1;i<=N;i++){
//		cout << rate[i] << " ";
//	}
//	cout << endl;
//	for(int i = 1;i<=M;i++){
//		cout << w[i] << " ";
//	}
	
	cout << ans << endl;
	return 0;
}


