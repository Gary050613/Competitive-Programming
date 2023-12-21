#include <bits/stdc++.h>
using namespace std;
char board[10][10];
string white, black;
// Input Uppercase letter
void search(char piece){
	if(isupper(piece)){
		for(int i = 8;i>=1;i--){
			for(int j = 1;j<=8;j++){
				if(board[i][j] == piece){
					if(!white.empty()) white=white+",";
					char ch = 'a'-1+j;
					if(piece=='P') white = white+ch+to_string(9-i);
					else white = white+piece+ch+to_string(9-i);
				}
			}
		}
	}else{
		for(int i = 1;i<=8;i++){
			for(int j = 1;j<=8;j++){
				if(board[i][j] == piece){
					if(!black.empty()) black=black+",";
					char ch = 'a'-1+j;
					piece = toupper(piece);
					if(piece=='P') black = black+ch+to_string(9-i);
					else black = black+piece+ch+to_string(9-i);
					piece = tolower(piece);
				}
			}
		}
	}
	
}

int main(){
	// 2 6 10 14 18 22 26 30
	string line;
	int row=1, column=1;
	for(int k=0;k<8;k++){
		getline(cin, line);
		getline(cin, line);
		column=1;
		for(int i = 2;i<33;i+=4){
			if(line[i]==':'||line[i]=='.'){
				board[row][column]=' ';
				column++;
			}else{
				board[row][column]=line[i];
				column++;
			}
		}
		row++;
	}
	getline(cin, line);
	search('K');
	search('Q');
	search('R');
	search('B');
	search('N');
	search('P');
	search('k');
	search('q');
	search('r');
	search('b');
	search('n');
	search('p');
	// Debug
//	for(int i = 1;i<=8;i++){
//		for(int j = 1;j<=8;j++){
//			cout << board[i][j] << " ";
//		}
//		cout << endl;
//	}
	cout << "White: " << white << endl;
	cout << "Black: " << black << endl;
	return 0;
}


