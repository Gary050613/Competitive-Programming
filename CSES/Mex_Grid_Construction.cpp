#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<int> column[105], row[105];

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 200; k++) {
                if (row[i].find(k) == row[i].end() && column[j].find(k) == column[j].end()) {
                    cout << k << " ";
                    row[i].insert(k);
                    column[j].insert(k);
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}