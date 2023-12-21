#include <bits/stdc++.h>
using namespace std;
string note[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"}, line;
const int scale[12] = {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1};

int getNote(string n){
    for(int i = 0;i<12;i++)
        if(n == note[i]) return i;
    return -1;
}

int main(){
    while(getline(cin, line) && line!="END"){
        stringstream ss(line);
        bool present[12] = {0}, first = 1;
        while(ss >> line) present[getNote(line)]=1;
        for(int i = 0;i<12;i++){
            bool fits=0;
            for(int j = 0;j<12;j++){
                if(present[(i+j)%12]){
                    if(scale[j]) fits = 1;
                    else{
                        fits = 0;
                        break;
                    }
                }
            }
            if(fits){
                if(!first) cout << " ";
                cout << note[i];
                first = 0;
            }
        }
        cout << "\n";
    }
    return 0;
}