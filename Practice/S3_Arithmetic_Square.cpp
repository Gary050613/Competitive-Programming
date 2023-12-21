#include <bits/stdc++.h>
using namespace std;
const int MM = 1e9+5;
const int rng = 1e9+1;
int board[3][3], h[3], v[3];
int db[3][3], dh[3], dv[3];
void inc(int i, int j){
    h[i]++, v[j]++;
}
bool fill(){
    bool flag = 1;
    while(flag){
        flag = 0;
        for(int i=0;i<3;i++){
            if(h[i]==2){
                for(int j=0;j<3;j++){
                    if(board[i][j]==MM){
                        if(j==0){board[i][0] = 2*board[i][1]-board[i][2]; if(board[i][0]>rng||board[i][0]<rng*-1) return false;}
                        if(j==1){if((board[i][0]+board[i][2])%2==1) return false; board[i][1] = (board[i][0]+board[i][2])/2;}
                        if(j==2){board[i][2] = 2*board[i][1]-board[i][0]; if(board[i][2]>rng||board[i][2]<rng*-1) return false;}
                        inc(i, j);
                    }
                }
                flag = 1;
            }
        }
        for(int j=0;j<3;j++){
            if(v[j]==2){
                for(int i=0;i<3;i++){
                    if(board[i][j]==MM){
                        if(i==0){board[0][j] = 2*board[1][j]-board[2][j]; if(board[0][j]>rng||board[0][j]<rng*-1) return false;}
                        if(i==1){if((board[0][j]+board[2][j])%2==1) return false; board[1][j] = (board[0][j]+board[2][j])/2;}
                        if(i==2){board[2][j] = 2*board[1][j]-board[0][j]; if(board[2][j]>rng||board[2][j]<rng*-1) return false;}
                        inc(i, j);
                    }
                }
                flag = 1;
            }
        }
    }
    return true;
}
int cntX(){
    int cnt = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) if(board[i][j]==MM) cnt++;
    }
    return cnt;
}
int main(){
    string str;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> str;
            if(str == "X") board[i][j] = MM;
            else {board[i][j] = stoi(str); inc(i, j);}
        }
    }
    if(cntX()==8){
        int x=1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) if(board[i][j] != MM) x = board[i][j];
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) cout << x << " ";
            cout << endl;
        }
        return 0;
    }else if(cntX()==9){
        cout << "1 1 1\n1 1 1\n1 1 1\n";
    }
    fill();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            db[i][j] = board[i][j];
        }
    }
    for(int i=0;i<3;i++){
        dh[i] = h[i], dv[i] = v[i];
    }
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++) cout << board[i][j] << " ";
    //     cout << endl;
    // }
    if(!cntX()){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) cout << board[i][j] << " ";
            cout << endl;
        }
    }else{
        for(int k=0;k<3;k++){
            if(h[k]==1){
                // reset
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        board[i][j] = db[i][j];
                    }
                }
                for(int i=0;i<3;i++){
                    h[i]=dh[i], v[i]=dv[i];
                }
                if(board[k][0]!=MM){board[k][1] = board[k][0]; board[k][2] = board[k][0]; inc(k, 1); inc(k, 2);}
                else if(board[k][1]!=MM){board[k][0] = board[k][1]; board[k][2] = board[k][1]; inc(k, 0); inc(k, 2);}
                else if(board[k][2]!=MM){board[k][0] = board[k][2]; board[k][1] = board[k][2]; inc(k, 0); inc(k, 1);}
                if(fill()) {
                    if(!cntX()){
                        for(int i=0;i<3;i++){
                            for(int j=0;j<3;j++) cout << board[i][j] << " ";
                            cout << endl;
                        }
                        return 0;
                    }else{
                        if(h[1]==1){
                            if(board[1][0]!=MM){board[1][1] = board[1][0]; board[1][2] = board[1][0]; inc(1, 1); inc(1, 2);}
                            else if(board[1][1]!=MM){board[1][0] = board[1][1]; board[1][2] = board[1][1]; inc(1, 0); inc(1, 2);}
                            else if(board[1][2]!=MM){board[1][0] = board[1][2]; board[1][1] = board[1][2]; inc(1, 0); inc(1, 1);}
                        }else if(v[1]==1){
                            if(board[0][1]!=MM){board[1][1] = board[0][1]; board[2][1] = board[0][1]; inc(1, 1); inc(2, 1);}
                            else if(board[1][1]!=MM){board[0][1] = board[1][1]; board[2][1] = board[1][1]; inc(0, 1); inc(2, 1);}
                            else if(board[2][1]!=MM){board[0][1] = board[2][1]; board[1][1] = board[2][1]; inc(0, 1); inc(1, 1);}
                        }
                        fill();
                        if(!cntX()){
                            for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++) cout << board[i][j] << " ";
                                cout << endl;
                            }
                            return 0;
                        }
                    }
                }
            }
        }
        for(int k=0;k<3;k++){
            if(v[k]==1){
                // reset
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        board[i][j] = db[i][j];
                    }
                }
                for(int i=0;i<3;i++){
                    h[i]=dh[i], v[i]=dv[i];
                }
                if(board[0][k]!=MM){board[1][k] = board[0][k]; board[2][k] = board[0][k]; inc(1, k); inc(2, k);}
                else if(board[1][k]!=MM){board[0][k] = board[1][k]; board[2][k] = board[1][k]; inc(0, k); inc(2, k);}
                else if(board[2][k]!=MM){board[0][k] = board[2][k]; board[1][k] = board[2][k]; inc(0, k); inc(1, k);}
                if(fill()) {
                    if(!cntX()){
                        for(int i=0;i<3;i++){
                            for(int j=0;j<3;j++) cout << board[i][j] << " ";
                            cout << endl;
                        }
                        return 0;
                    }else{
                        if(h[1]==1){
                            if(board[1][0]!=MM){board[1][1] = board[1][0]; board[1][2] = board[1][0]; inc(1, 1); inc(1, 2);}
                            else if(board[1][1]!=MM){board[1][0] = board[1][1]; board[1][2] = board[1][1]; inc(1, 0); inc(1, 2);}
                            else if(board[1][2]!=MM){board[1][0] = board[1][2]; board[1][1] = board[1][2]; inc(1, 0); inc(1, 1);}
                        }else if(v[1]==1){
                            if(board[0][1]!=MM){board[1][1] = board[0][1]; board[2][1] = board[0][1]; inc(1, 1); inc(2, 1);}
                            else if(board[1][1]!=MM){board[0][1] = board[1][1]; board[2][1] = board[1][1]; inc(0, 1); inc(2, 1);}
                            else if(board[2][1]!=MM){board[0][1] = board[2][1]; board[1][1] = board[2][1]; inc(0, 1); inc(1, 1);}
                        }
                        fill();
                        if(!cntX()){
                            for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++) cout << board[i][j] << " ";
                                cout << endl;
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}