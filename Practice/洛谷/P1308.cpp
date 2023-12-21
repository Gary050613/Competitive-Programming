#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string word, line;
	int ans = -1, start = 0;
	getline(cin, word);
	getline(cin, line);
	int lenW = word.length(), lenL = line.length();
	for(int i = 0;i<lenW;i++){
		if(word[i] == ' '){
			continue;
		}
		if(word[i]<'a'){
			word[i] = word[i] + 32;
		}
	}
	for(int i = 0;i<lenL;i++){
		if(line[i] == ' '){
			continue;
		}
		if(line[i]<'a'){
			line[i] = line[i] + 32;
		}
	}
	int i = 0;
	while(i < lenL){
		for(int j = 0;j<lenW;j++){
			if(word[j] != line[i+j]){
				break;
			}
			if(j == lenW-1 && (i==0 || line[i-1] == ' ') && (line[i+lenW] == '\0' || line[i+lenW] == ' ')){
				if(ans == -1){
					ans = 0;
					start = i;
				}
				ans++;
			}
		}
		i++;
	}
	if(ans != -1){
		printf("%d %d", ans, start);
	}else{
		printf("-1\n");
	}
	
	return 0;
}


