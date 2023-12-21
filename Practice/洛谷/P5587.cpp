#include <bits/stdc++.h>
using namespace std;

int T, sizeT = 0, sizeI = 0, ans=0;
string text[10001], input[10001], str;

int main(){
	
	while(getline(cin, str) && str != "EOF"){
		for(int i = 0;i<str.length();i++){
			if(str[i] == '<'){
				if(!text[sizeT].empty()){
					text[sizeT].pop_back();
				}
			}else{
				text[sizeT].push_back(str[i]);
			}
		}
		sizeT++;
	}
	while(getline(cin, str) && str != "EOF"){
		for(int i = 0;i<str.length();i++){
			if(str[i] == '<'){
				if(!input[sizeI].empty()){
					input[sizeI].pop_back();
				}
			}else{
				input[sizeI].push_back(str[i]);
			}
		}
		for(int i = 0;i<text[sizeI].length() && i<input[sizeI].length();i++){
			if(text[sizeI][i] == input[sizeI][i]){
				ans++;
			}
		}
		sizeI++;
	}
	scanf("%d", &T);
	printf("%d\n", (int)(ans*60.0)/T);
//	for(int i = 0;i<sizeT;i++){
//		cout << text[i] << endl;
//	}
//	for(int i = 0;i<sizeI;i++){
//		cout << input[i] << endl;
//	}
	
	return 0;
}


