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

const int X = 23895365;
const int MOD = 1e9 + 7;
const int MN = 1e5 + 5;
int n;
string str;
int pws[MN], hashes[MN], sa[MN];
int ansDif[MN];

int lcp(int a, int b){
    int lo = 0, hi = n - max(a, b);
    while(lo < hi){
        int mid = (lo+hi+1)/2;
        ll h1 = hashes[a+mid] - (ll) pws[mid]*hashes[a];
        ll h2 = hashes[b+mid] - (ll) pws[mid]*hashes[b];
        if((h1-h2) % MOD) hi = mid-1;
        else lo = mid;
    }
    return lo;
}

bool cmp(int a, int b){
    int l = lcp(a, b);
    return str[a+l] < str[b+l];
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    pws[0] = 1;
    FR(i, MN-1) pws[i+1] = (ll) pws[i] * X % MOD;
    cin >> str;
    n = SZ(str);
    FR(i, n) hashes[i+1] = ((ll) hashes[i]*X + str[i]) % MOD;
    iota(sa, sa + n, 0);
    sort(sa, sa + n, cmp);

    ansDif[0]++;
    ansDif[n-sa[0]]--;

    FR(i, n-1){
        int a = sa[i], b = sa[i+1];
        int l = lcp(a, b);
        ansDif[l]++;
        ansDif[n-b]--;
    }

    int cur = 0;
    FR(i, n){
        cur += ansDif[i];
        cout << cur << " \n"[i == n-1];
    }
}
