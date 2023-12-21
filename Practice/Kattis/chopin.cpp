#include <bits/stdc++.h>
using namespace std;
string str;
int t = 1;
map<string, string> mp;
int main()
{
    mp["A#"] = "Bb";
    mp["C#"] = "Db";
    mp["D#"] = "Eb";
    mp["F#"] = "Gb";
    mp["G#"] = "Ab";
    mp["Bb"] = "A#";
    mp["Db"] = "C#";
    mp["Eb"] = "D#";
    mp["Gb"] = "F#";
    mp["Ab"] = "G#";
    while (getline(cin, str))
    {
        if (str[1] == ' ')
        {
            printf("Case %d: UNIQUE\n", t++);
        }
        else
        {
            cout << "Case " << t++ << ": " << mp[str.substr(0, 2)] << " " << str.substr(3, 5) << endl;
        }
    }
    return 0;
}