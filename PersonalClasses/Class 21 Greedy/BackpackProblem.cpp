#include <bits/stdc++.h>
using namespace std;

struct item{
	double v, w, avg;
} items[101];

bool cmp(item i1, item i2){
	if(i1.avg > i2.avg){
		return true;
	}
	return false;
}

int main(){
	
	int c = 150, n, index = 0;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> items[i].w >> items[i].v;
		items[i].avg = items[i].v / items[i].w;
	}
	sort(items, items+n, cmp);
	while(c > 0){
		if(items[index].w <= c){
			c -= items[index].w;
			cout << items[index].w << " " << items[index].v << endl;
			index++;
		}else{
			cout << c << " " << items[index].v << endl;
			break;
		}
	}
	
	return 0;
}
/*
7
35 10
30 40
60 30
50 50
40 35
10 40
25 30
*/


