#include <bits/stdc++.h>
using namespace std;
int hor[12] = {4, 5, 7, 1, 6, 3, 8, 2, 11, 0, 9, 10};
int ver[12];
string notes[12] = {"C ", "Db", "D ", "Eb", "E ", "F ", "Gb", "G ", "Ab", "A ", "Bb", "B "};

int main(){
    for(int i=0;i<12;i++) ver[i]=(20-hor[i])%12;
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            int index = (hor[j]+ver[i]+12-4)%12;
            cout << notes[index] << " ";
        }
        cout << endl;
    }
    return 0;
}