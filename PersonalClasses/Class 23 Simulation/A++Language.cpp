#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int t, L, time, m, cur = 0, ans = 0, error = 0;
	char complexity[11], code, i, x, y;
	cin >> t;
	while(t--){
		stack<char> s;
		vector<char> v;
		cin >> L >> complexity;
		if(complexity[2] == '1'){
			time = 0;
		}else{
			time = complexity[4]-'0';
		}
		cur = 0, error = 0;
		int maxn = 100, m = 0, ignore = 0;
		while(L--){
			cin >> code;
			if(ignore){
				if(code == 'F'){
					ignore++;
				}else if(code == 'E'){
					ignore--;
				}
			}
			if(code == 'F'){
				cin >> i >> x >> y;
				for(int j = 0;j<v.size();j++){
					if(v[j] == i){
						error = 1;
						break;
					}
				}
				v.push_back(i);
				s.push(i);
				if(x == 'n' && y != 'n'){
					if(y-'0'<maxn){
						maxn = y-'0';
					}else{
						// ignores all inside loop
						if(!ignore){
							ignore = 1;
						}
					}
				}else if(x != 'n' && y == 'n'){
					if(x-'0'<maxn){
						m = max(m, ++cur);
					}else{
						// ignores all inside loop
						if(!ignore){
							ignore = 1;
						}
					}
				}else{
					continue;
				}
			}else if(code == 'E'){
				if(s.empty()){
					error = 1;
					continue;
				}
				v.pop_back();
				s.pop();
				if(s.empty()){
					ans = max(ans, m);
					m = 0;
				}
			}
		}
		if(error){
			printf("ERR\n");
		}else{
			if(ans == time){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}
	}
	
	return 0;
}

/*
8
2 O(1)
F i 1 1
E
2 O(n^1)
F x 1 n
E
1 O(1)
F x 1 n
4 O(n^2)
F x 5 n
F y 10 n
E
E
4 O(n^2)
F x 9 n
E
F y 2 n
E
4 O(n^1)
F x 9 n
F y n 4
E
E
4 O(1)
F y n 4
F x 9 n
E
E
4 O(n^2)
F x 1 n
F x 1 10
E
E
*/
