#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[25];

int ind, pos;

ll q, num;

ll k;

int main(){
    for (int i = 1; i <= 18; i++) {
        arr[i] = pow(10, i-1) * 9 * i;
    }
    cin >> q;
    while (q--) {
        cin >> k;
        ind = 1;
        while (k > arr[ind]) {
            k -= arr[ind++];
        }
        // cout << "ind: " << ind << endl;
        // cout << "k: " << k << endl;
        if (ind == 1) num = k;
        else {
            num = pow(10, ind-1);
            num--;
            num += (k + ind - 1) / ind;
        }
        // cout << num << endl;
        pos = ind - 1 - (k - 1) % ind;
        while(pos--) {
            num /= 10;
        }
        cout << num % 10 << endl;
    }
    return 0;
}