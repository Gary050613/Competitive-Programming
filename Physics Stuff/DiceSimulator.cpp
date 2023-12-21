#include <bits/stdc++.h>
using namespace std;
double sum=0, rounds=0, trials;
int main(){
    cin >> trials;
    for(int i=0;i<trials;i++){
        // sum = 0;
        // rounds = 0;
        while(true){
            int roll = rand() % 6 + 1;
            if(roll == 5){
                break;
            }else{
                sum += roll;
                rounds++;
            }
        }
    }
    cout << "Avg sum: " << sum/trials << endl;
    cout << "Avg rounds: " << rounds/trials << endl;
    return 0;
}