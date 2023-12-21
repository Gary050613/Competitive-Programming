#include <bits/stdc++.h>
using namespace std;
int s, e, ans;
int main()
{
    cin >> s >> e;
    if (e >= s)
    {
        ans = e - 360 - s;
        if (e - s <= abs(ans))
            ans = e - s;
    }
    else
    {
        ans = e - s;
        if (e + 360 - s <= abs(ans))
            ans = e + 360 - s;
    }
    cout << ans << endl;
    return 0;
}