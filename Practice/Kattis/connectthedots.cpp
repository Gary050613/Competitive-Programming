#include <bits/stdc++.h>
using namespace std;
char img[101][101], ch; int h=0, w=0, cur=0; string order = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", str;

struct dots{
	int x, y;
	char v;
} d[101];

bool cmp(dots d1, dots d2){
	return order.find(d1.v) < order.find(d2.v);
}

void process(){
	for(int i = 0;i<h;i++){
				for(int j = 0;j<w;j++){
					if(img[i][j] != '.'){
						d[cur].x = i, d[cur].y = j, d[cur].v = img[i][j];
						cur++;
					}
				}
			}
			sort(d, d+cur, cmp);
//			for(int i = 0;i<cur;i++) cout << d[i].v << " ";
//			cout << endl;
			// x = height, y = width;
			// traverse d array
			for(int k = 0;k<cur-1;k++){
				// if x is the same replace interval with '-'
				if(d[k].x == d[k+1].x){
					// if k.y < k+1.y
					if(d[k].y < d[k+1].y){
						for(int i = d[k].y+1;i<d[k+1].y;i++){
							if(img[d[k].x][i] == '.') img[d[k].x][i] = '-';
							else if(img[d[k].x][i] == '|') img[d[k].x][i] = '+';
						}
					}else{
						for(int i = d[k+1].y+1;i<d[k].y;i++){
							if(img[d[k].x][i] == '.') img[d[k].x][i] = '-';
							else if(img[d[k].x][i] == '|') img[d[k].x][i] = '+';
						}
					}
				}
				// if y is the same replace interval with '|'
				if(d[k].y == d[k+1].y){
					// if k.x < k+1.x
					if(d[k].x < d[k+1].x){
						for(int i = d[k].x+1;i<d[k+1].x;i++){
							if(img[i][d[k].y] == '.') img[i][d[k].y] = '|';
							else if(img[i][d[k].y] == '-') img[i][d[k].y] = '+';
						}
					}else{
						for(int i = d[k+1].x+1;i<d[k].x;i++){
							if(img[i][d[k].y] == '.') img[i][d[k].y] = '|';
							else if(img[i][d[k].y] == '-') img[i][d[k].y] = '+';
						}
					}
				}
				// if img[i][j] already has '-'or'|' replace with '+'
			}
			for(int i = 0;i<h;i++){
				for(int j = 0;j<w;j++){
					cout << img[i][j];
				}
				cout << endl;
			}
			h = 0, w = 0, cur=0;
}

int main(){
	while(getline(cin, str)){
//		cout << str << endl;
		if(str == ""){
			process();
			cout << endl;
			continue;
		}
		w = str.length();
		for(int j = 0;j<w;j++){
			img[h][j] = str[j];
		}
		h++;
	}
	process();
	return 0;
}


