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
template <typename T, typename U>
ostream& operator<<(ostream &os, pair<T, U> p){return os << "(" << p.fs << ", " << p.sn << ")";}

const int BSZ = 400;
const int BC = 501;
const int MN = BSZ*BC;
int n, q;
ll arr[MN];
ll lazyAdd[MN];

void pushDown(int bi){
    for(int i = bi*BSZ; i < (bi+1)*BSZ; i++) arr[i] += lazyAdd[bi];
    lazyAdd[bi] = 0;
}

// Add v to [l, r)
void upd(int l, int r, int v){
    int lBlock = l/BSZ;
    int rBlock = r/BSZ;

    if(lBlock == rBlock){
        pushDown(lBlock);
        for(int i = l; i < r; i++) arr[i] += v;
        return;
    }

    pushDown(lBlock);
    pushDown(rBlock);
    for(int i = l; i < (lBlock+1)*BSZ; i++) arr[i] += v;
    for(int i = rBlock*BSZ; i < r; i++) arr[i] += v;
    for(int i = lBlock+1; i < rBlock; i++) lazyAdd[i] += v;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];

    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r, v;
            cin >> l >> r >> v;
            l--;
            upd(l, r, v);
        }
        else {
            int p; cin >> p; p--;
            pushDown(p/BSZ);
            cout << arr[p] << '\n';
        }
    }
}
