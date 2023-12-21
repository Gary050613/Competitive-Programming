#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct student{
	ll position, weight, distance;
} s[200001];
int N;
ll start = INT_MAX, mid, cost, ans = INT_MAX;
bool cmp(student s1, student s2){
	return s1.position < s2.position;
}

ll getCost(ll location){
	ll ans = 0;
	for(int i = 1;i<=N;i++){
		if(abs(location-s[i].position) > s[i].distance){
			ans += (abs(location-s[i].position)-s[i].distance) * s[i].weight;
		}
	}
	return ans;
}

int main(){
	
	
	cin >> N;
	for(int i = 1;i<=N;i++){
		cin >> s[i].position >> s[i].weight >> s[i].distance;
	}
	if(N == 1){
		cout << 0 << endl;
	}else{
		sort(s+1,s+1+N,cmp);
		for(int i = 1;i<=N;i++){
			cost = getCost(s[i].position);
			if(cost < start){
				start = cost;
				mid = i;
			}
		}
//		for(int i = s[1].position;i<=s[N].position;i++){
//			ans = min(ans, getCost(i));
//		}
		ll start = s[mid-1].position, end = s[mid+1].position;
		if(start == 0 && end == 0){
			ans = getCost(s[mid].position);
		}else if(start == 0){
			for(int i = s[mid].position;i<=end;i++){
				ans = min(ans, getCost(i));
			}
		}else if(end == 0){
			for(int i = start;i<=s[mid].position;i++){
				ans = min(ans, getCost(i));
			}
		}else{
			for(int i = start;i<=end;i++){
				ans = min(ans, getCost(i));
			}
		}
		
	//	cout << start << " " << end << endl;
		cout << ans << endl;
	//	for(int i = 1;i<=N;i++){
	//		cout << cost[i] << " ";
	//	}	
	}

	
	return 0;
}


