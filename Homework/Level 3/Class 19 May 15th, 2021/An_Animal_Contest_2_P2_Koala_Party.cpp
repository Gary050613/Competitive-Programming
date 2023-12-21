#include <bits/stdc++.h>
using namespace std;
const int MM = 4e3 + 5;
int N, a[MM];
set<int> st;
int main()
{
    // Only 3 answers, 1, 2, 3.
    // Condition of 3 : (x+y)/2 == z
    // Condition of 2 : (x+y)%2 == 0
    // Condition of 1 : !C3 && !C2
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }
    if (N == 2)
    {
        if ((a[0] + a[1]) % 2 == 1)
            cout << 1 << endl;
        else
            cout << 2 << endl;
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (st.count((a[i] + a[j]) / 2) && (a[i] + a[j]) % 2 == 0)
            {
                cout << 3 << endl;
                return 0;
            }
        }
    }
    cout << 2 << endl;
    return 0;
}