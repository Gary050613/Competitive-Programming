#include <bits/stdc++.h>
using namespace std;
// board[col][row]
char board[10][10];

void printBoard(){
	// Top line
	for(int i=0;i<8;i++){
		cout << "+---";
	}
	cout << "+\n";
	// Middle Content (i=row, j=col)
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			cout << "|";
			if((i+j)%2==0) cout << "." << board[j][i] << ".";
			else cout << ":" << board[j][i] << ":";
		}
		cout << "|\n";
		for(int i=0;i<8;i++){
			cout << "+---";
		}
		cout << "+\n";
	}
}

int main(){
	string white, black;
	getline(cin, white);
	getline(cin, black);
	for(int i = 1;i<=8;i++){
		for(int j = 1;j<=8;j++){
			if((i+j)%2==0) board[j][i] = '.';
			else board[j][i] = ':';
		}
	}
	for(int i = 7;i<white.length();i++){
		if(isupper(white[i])){
			board[white[i+1]-'a'+1][9-(white[i+2]-'0')] = white[i];
			i+=3;
		}else{
			board[white[i]-'a'+1][9-(white[i+1]-'0')] = 'P';
			i+=2;
		}
	}
	for(int i = 7;i<black.length();i++){
		if(isupper(black[i])){
			board[black[i+1]-'a'+1][9-(black[i+2]-'0')] = tolower(black[i]);
			i+=3;
		}else{
			board[black[i]-'a'+1][9-(black[i+1]-'0')] = 'p';
			i+=2;
		}
	}
	printBoard();
	
//	for(int i = 1;i<=8;i++){
//		for(int j = 1;j<=8;j++){
//			cout << board[j][i] << " ";
//		}
//		cout << endl;
//	}
	
	return 0;
}


