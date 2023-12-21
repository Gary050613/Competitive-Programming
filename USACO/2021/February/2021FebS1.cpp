#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
#define ii pair<int, int>
#define ll long long
using namespace std;
int adj[3010][3010]={0};
bool cow[3010][3010]={0}, vis[3010][3010]={0}; // cow for placement, vis for imaginary cows
int nx[4]={0, 0, -1, 1};
int ny[4]={-1, 1, 0, 0};
queue<ii> q;
ll ans = 0;
void update(int x, int y){
	cow[x][y] = 1;
	for(int i = 0;i<4;i++){
		int x1 = x + nx[i];
		int y1 = y + ny[i];
		adj[x1][y1]++;
		if(adj[x1][y1] == 3 && cow[x1][y1]){
			q.push(mp(x1, y1));
		}
		if(adj[x][y] == 3 && cow[x][y]){
			q.push(mp(x,y));
		}
	}
}

int main(){
	int n;
	cin >> n;
	while(n--){
		int x, y;
		cin >> x >> y;
		x+=1001;
		y+=1001;
		if(vis[x][y]){
			cow[x][y] = 1;
			vis[x][y] = 0;
			ans--;
			cout << ans << endl;
			continue;
		}
		update(x, y);
		while(!q.empty()){
			ii i = q.front();
			for(int j = 0;j<4;j++){
				int x1 = i.f + nx[j];
				int y1 = i.s + ny[j];
				if(!cow[x1][y1]){
					update(x1, y1);
					vis[x1][y1]=1;
					ans++;
				}
			}
			q.pop();
		}
		cout << ans << endl;
	}
	return 0;
}
