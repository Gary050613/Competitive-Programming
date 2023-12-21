#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int n = 1;
	while(cin >> s && s != "#"){
		if(s == "HELLO"){
			printf("Case %d: ENGLISH\n", n++);
		}else if(s == "HOLA"){
			printf("Case %d: SPANISH\n", n++);
		}else if(s == "HALLO"){
			printf("Case %d: GERMAN\n", n++);
		}else if(s == "BONJOUR"){
			printf("Case %d: FRENCH\n", n++);
		}else if(s == "CIAO"){
			printf("Case %d: ITALIAN\n", n++);
		}else if(s == "ZDRAVSTVUJTE"){
			printf("Case %d: RUSSIAN\n", n++);
		}else{
			printf("Case %d: UNKNOWN\n", n++);
		}
	}
	return 0;
}


