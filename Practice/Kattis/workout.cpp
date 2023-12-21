// I don't know how I solved this, I'm fking genius

#include <bits/stdc++.h>
using namespace std;
int jim[10][2], others[10][3], cur=0/*, machines[10][10000005]={0}*/;

// void update(int t, int task){
//     for(int j = 0;j<=10000005-t;j++){
//         if(j%(others[task][0]+others[task][1])<others[task][0]) machines[task][t+j] = 1;
//         else machines[task][t+j] = 0;
//     }
// }

int main(){
    for(int i = 0;i<10;i++) cin >> jim[i][0] >> jim[i][1];
    // u r t
    for(int i = 0;i<10;i++) cin >> others[i][0] >> others[i][1] >> others[i][2];
    // for(int i = 0;i<10;i++) update(others[i][2], i);
    // for(int i = 0;i<10;i++) {for(int j = 0;j<10;j++) cout << machines[i][j] << " "; cout << endl;}
    for(int i = 0;i<30;i++){
        // Condition: cur < t || (cur-t)%(u+r) >= u
        int task = i%10;
        while(!(cur < others[task][2] || (cur-others[task][2])%(others[task][0]+others[task][1])>=others[task][0])){
            cur++;
        }
        bool flag=0;
        for(int j = cur;j<jim[task][0]+cur;j++) if(j >= others[task][2] && (j-others[task][2])%(others[task][0]+others[task][1])<others[task][0]) flag = 1;
        cur += jim[task][0];
        if(flag) others[task][2] = cur;
        if(i!=29) cur+= jim[task][1];
        // cout << cur << " ";
    }
    // for(int i = 0;i<30;i++){
    //     int task = i%10;
    //     // Occupied
    //     while(machines[task][cur]) cur++;
    //     // Unoccupied: Update current time
    //     bool flag=0;
    //     for(int j = cur;j<jim[task][0]+cur;j++) if(machines[task][j]) flag = 1;
    //     cur += jim[task][0];
    //     if(i!=29) cur+=jim[task][1];
    //     if(flag) {update(cur, task); /*cout << "Update on:" << cur << " " << task << endl; for(int j = 0;j<10;j++) cout << machines[task][j] << " "; cout << endl;*/}
    // }
    cout << cur << endl;
    return 0;
}

/*
5 5 3 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
        0 1 2 3 4 5 6 7 8 9 10 11
2 2 1   0 1 1 0 0 1 1 0 0 1 1  0  0
8 3 0   1 1 1 1 1 1 1 1 0 0 0  1  1
1 1 0   
1 1 0   
1 1 0   
1 1 0   
1 1 0   
1 1 0   
1 1 0   
1 1 0   

*/