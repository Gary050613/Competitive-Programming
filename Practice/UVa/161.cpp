#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
int a, b, c;
vi vec;

bool allGreen(int t)
{
    int count = 0;
    bool org = false;
    for (int i = 0; i < vec.size(); i++)
    {
        if (t % (vec[i] * 2) < vec[i] - 5)
        {
            count++;
        }
        if (t > vec[i])
        {
            org = true;
        }
    }
    if (count == vec.size() && org)
    {
        return true;
    }
    return false;
}

int main()
{
    while (cin >> a >> b >> c && (a || b || c))
    {
        bool ans = false;
        int res;
        vec.clear();
        vec.pb(a);
        vec.pb(b);
        while (c != 0)
        {
            vec.pb(c);
            cin >> c;
        }
        for (int i = 1; i <= 18000; i++)
        {
            if (allGreen(i))
            {
                ans = true;
                res = i;
                break;
            }
        }
        if (ans)
            printf("%02d:%02d:%02d\n", res / 3600, (res % 3600) / 60, res % 60);
        else
            cout << "Signals fail to synchronise in 5 hours\n";
    }
    return 0;
}