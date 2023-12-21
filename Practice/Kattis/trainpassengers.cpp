#include <bits/stdc++.h>
using namespace std;
int C, n, out, in, stay, cur = 0;
bool ans = true;
int main()
{
    cin >> C >> n;
    while (n--)
    {
        cin >> out >> in >> stay;
        cur -= out;
        if (cur < 0)
            ans = false;
        cur += in;
        if (cur > C)
            ans = false;
        if (cur < C && stay > 0)
            ans = false;
        if (n == 0 && cur > 0)
            ans = false;
    }
    if (ans)
        cout << "possible\n";
    else
        cout << "impossible\n";
    return 0;
}