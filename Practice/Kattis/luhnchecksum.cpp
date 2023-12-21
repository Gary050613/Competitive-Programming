#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, sum = 0, temp, cur;
string n;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n.length(); i++)
        {
            cur = n[n.length() - i] - '0';
            // cout << cur << " ";
            if (i % 2 == 1)
            {
                sum += cur;
            }
            else
            {
                if (cur * 2 >= 10)
                {
                    sum += (cur * 2) % 10 + 1;
                }
                else
                {
                    sum += cur * 2;
                }
            }
        }
        // cout << sum << endl;
        if (sum % 10 == 0)
            cout << "PASS\n";
        else
            cout << "FAIL\n";
    }
    return 0;
}