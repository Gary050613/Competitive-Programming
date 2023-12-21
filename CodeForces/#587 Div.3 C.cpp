#include <bits/stdc++.h> // Include every standard library
using namespace std;
  
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
  
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };
  
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)

pair<pii, pii> intersect(pii a, pii b, pii c, pii d){
    int xL = max(a.fi, c.fi);
    int xR = min(b.fi, d.fi);
    int yL = max(a.se, c.se);
    int yR = min(b.se, d.se);
    if(xL < xR && yL < yR) return mp(mp(xL, yL), mp(xR, yR));
    else return {{0, 0}, {0, 0}};
}

LL area(pii a, pii b){
    return 1LL * (b.fi - a.fi) * (b.se - a.se);
}

int main(){
    pii p[6];
    REP(i, 6) cin >> p[i].fi >> p[i].se;
    pair<pii, pii> wb1 = intersect(p[0], p[1], p[2], p[3]);
    pair<pii, pii> wb2 = intersect(p[0], p[1], p[4], p[5]);
    pair<pii, pii> inter = intersect(wb1.fi, wb1.se, wb2.fi, wb2.se);
    
    LL white = area(p[0], p[1]);
    LL s1 = area(wb1.fi, wb1.se);
    LL s2 = area(wb2.fi, wb2.se);
    LL mid = area(inter.fi, inter.se);
    if(white-s1-s2+mid <= 0) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}
