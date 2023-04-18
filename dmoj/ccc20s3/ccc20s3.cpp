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

const int MZ = 26;
const int X = 100;
const ll MOD = 1e16 + 61;
int n, m;
string str, key;
int keyFreq[MZ], strFreq[MZ];
vector<ll> hashVec;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> key >> str;
    n = SZ(str); m = SZ(key);
    for(char &ch : str) ch -= 'a';
    for(char &ch : key) ch -= 'a';
    for(char ch : key) keyFreq[ch]++;

    ll pw = 1;
    FR(i, m) pw = pw*X % MOD;

    ll strHash = 0;
    FR(i, m){
        strHash = (strHash*X + str[i]) % MOD;
        strFreq[str[i]]++;
    }

    FR(i, n-m+1){
        if(memcmp(keyFreq, strFreq, sizeof(keyFreq)) == 0) hashVec.pb(strHash);
        strHash = (strHash*X + str[i+m] - pw*str[i]) % MOD;
        if(strHash < 0) strHash += MOD;
        strFreq[str[i]]--;
        strFreq[str[i+m]]++;
    }

    sort(ALL(hashVec));
    hashVec.resize(unique(ALL(hashVec)) - hashVec.begin());
    cout << SZ(hashVec) << '\n';
}
