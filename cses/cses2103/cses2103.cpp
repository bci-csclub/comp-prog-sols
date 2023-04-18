#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cpx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define fs first
#define sn second
#define ALL(v) begin(v), end(v)
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound(ALL(v), x) - (v).begin())
#define ubv(v, x) (upper_bound(ALL(v), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x) {cerr << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}

const int X = 589472134;
const int MOD = 1e9 + 7;
const int MN = 1e5 + 5;

struct Str {
    int len;
    char *str;
    int *hashes;
};

int n, q;
int pws[MN];
string str, qStr;
int hashes[MN], qHashes[MN];
Str sa[MN];

int lcp(const Str &a, const Str &b){
    int lo = 0, hi = min(a.len, b.len);
    while(lo < hi){
        int mid = (lo+hi+1)/2;
        ll h1 = a.hashes[mid] - (ll) pws[mid]*a.hashes[0];
        ll h2 = b.hashes[mid] - (ll) pws[mid]*b.hashes[0];
        if((h1-h2) % MOD) hi = mid-1;
        else lo = mid;
    }
    return lo;
}

bool operator<(const Str &a, const Str &b){
    int l = lcp(a, b);
    return a.str[l] < b.str[l];
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    pws[0] = 1;
    FR(i, MN-1) pws[i+1] = (ll) pws[i] * X % MOD;

    cin >> str;
    n = SZ(str);
    FR(i, n) hashes[i+1] = ((ll) hashes[i]*X + str[i]) % MOD;
    FR(i, n) sa[i] = {n-i, &str[i], hashes + i};
    sort(sa, sa + n);

    cin >> q;
    while(q--){
        cin >> qStr;
        int m = SZ(qStr);
        if(m > n){
            cout << "0\n";
            continue;
        }

        FR(i, m) qHashes[i+1] = ((ll) qHashes[i]*X + qStr[i]) % MOD;
        int l = lower_bound(sa, sa + n, Str{m, &qStr[0], qHashes}) - sa;

        qStr.pb(126);
        qHashes[m+1] = ((ll) qHashes[m]*X + qStr[m]) % MOD;
        int r = upper_bound(sa, sa + n, Str{m+1, &qStr[0], qHashes}) - sa;

        cout << r-l << '\n';
    }
}
