#include <bits/stdc++.h>
using namespace std;
int N, arr[150] = {0}, ans = 0;
string str;
int main()
{
    cin >> N >> str;
    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i]]++;
    }
    for (int i = 0; i < 150; i++)
    {
        if (arr[i] % 2 == 1)
            ans++;
    }
    cout << max(1, ans) << endl;
    return 0;
}