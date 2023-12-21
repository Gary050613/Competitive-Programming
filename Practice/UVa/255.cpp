#include <bits/stdc++.h>
using namespace std;

int main(){
	int K, Q, N;
	while(cin >> K >> Q >> N){
		int kx = K/8, ky = K%8, qx = Q/8, qy = Q%8, nx = N/8, ny = N%8;
		int dx[20], dy[20], cnt=0;
		bool flag=0;
		// UP
		for(int i = qx-1;i>=0;i--){
			if(qy==ky&&i==kx){
				break;
			}
			dx[cnt]=i;
			dy[cnt++]=qy;
		}
		// DOWN
		for(int i = qx+1;i<8;i++){
			if(qy==ky&&i==kx){
				break;
			}
			dx[cnt]=i;
			dy[cnt++]=qy;
		}
		// LEFT
		for(int j = qy-1;j>=0;j--){
			if(j==ky&&qx==kx){
				break;
			}
			dx[cnt]=qx;
			dy[cnt++]=j;
		}
		// RIGHT
		for(int j = qy+1;j<8;j++){
			if(j==ky&&qx==kx){
				break;
			}
			dx[cnt]=qx;
			dy[cnt++]=j;
		}
		for(int i = 0;i<cnt;i++){
			if(dx[i]==nx&&dy[i]==ny) flag=1;
		}
		if(K == Q){
			cout << "Illegal state\n";
			//K == N || Q == N || (qx!=nx && qy!=ny)
		}else if(!flag){
			cout << "Illegal move\n";
		}else if((nx==kx-1&&ny==ky)||(nx==kx+1&&ny==ky)||(nx==kx&&ny==ky-1)||(nx==kx&&ny==ky+1)){
			cout << "Move not allowed\n";
		}else if((K==0&&N==9)||(K==7&&N==14)||(K==56&&N==49)||(K==63&&N==54)){
			cout << "Stop\n";
		}else{
			cout << "Continue\n";
		}
	}
	return 0;
}


