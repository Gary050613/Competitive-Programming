#include <bits/stdc++.h>
using namespace std;

struct event{
	int start, end;
} events[1001];

bool cmp(event a, event b){
	if(a.end < b.end){
		return true;
	}
	if(a.end == b.end){
		return a.start > b.start;
	}
	return false;
}

int main(){
	
	int n, ans = 1, cur;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> events[i].start >> events[i].end;
	}
	sort(events+1, events+1+n, cmp);
	cur = events[1].end;
	for(int i = 2;i<=n;i++){
		if(cur <= events[i].start){
			cur = events[i].end;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

/*
5
3 5
1 4
7 9
8 10
1 6
*/
