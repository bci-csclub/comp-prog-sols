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

const int BSZ = 250;
const int BC = 801;
const int MN = BSZ*BC;
int n, q;
ll arr[MN];
ll blkSum[BC]; // sum of each block
ll lazySet[BC]; // amount to set each value in the block to, or -1 to indicate no set
ll lazyAdd[BC]; // amount to add to each value in the block. Applied after lazySet

void recalc(int bi){
    ll sm = 0;
    for(int i = bi*BSZ; i < (bi+1)*BSZ; i++) sm += arr[i];
    blkSum[bi] = sm;
}

void pushDown(int bi){
    if(lazySet[bi] != -1){
        for(int i = bi*BSZ; i < (bi+1)*BSZ; i++) arr[i] = lazySet[bi];
        lazySet[bi] = -1;
    }
    if(lazyAdd[bi] != 0){ // condition can also be omitted
        for(int i = bi*BSZ; i < (bi+1)*BSZ; i++) arr[i] += lazyAdd[bi];
        lazyAdd[bi] = 0;
    }
}

void upd(int l, int r, int setV, int addV){
    int lBlock = l/BSZ;
    int rBlock = r/BSZ;

    if(lBlock == rBlock){
        pushDown(lBlock);
        if(setV != -1) for(int i = l; i < r; i++) arr[i] = setV;
        if(addV != 0) for(int i = l; i < r; i++) arr[i] += addV;
        recalc(lBlock);
        return;
    }

    pushDown(lBlock);
    pushDown(rBlock);

    if(setV != -1){
        for(int i = l; i < (lBlock+1)*BSZ; i++) arr[i] = setV;
        for(int i = rBlock*BSZ; i < r; i++) arr[i] = setV;
        for(int i = lBlock+1; i < rBlock; i++){
            lazyAdd[i] = 0;
            lazySet[i] = setV;
            blkSum[i] = setV*BSZ;
        }
    }
    if(addV != 0){
        for(int i = l; i < (lBlock+1)*BSZ; i++) arr[i] += addV;
        for(int i = rBlock*BSZ; i < r; i++) arr[i] += addV;
        for(int i = lBlock+1; i < rBlock; i++){
            lazyAdd[i] += addV;
            blkSum[i] += addV*BSZ;
        }
    }

    recalc(lBlock);
    recalc(rBlock);
}

ll query(int l, int r){
    ll res = 0;
    int lBlock = l/BSZ;
    int rBlock = r/BSZ;

    if(lBlock == rBlock){
        pushDown(lBlock);
        for(int i = l; i < r; i++) res += arr[i];
        return res;
    }

    pushDown(lBlock);
    pushDown(rBlock);

    for(int i = l; i < (lBlock+1)*BSZ; i++) res += arr[i];
    for(int i = rBlock*BSZ; i < r; i++) res += arr[i];
    for(int i = lBlock+1; i < rBlock; i++) res += blkSum[i];
    return res;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];

    fill(ALL(lazySet), -1);
    for(int i = 0; i < BC; i++) recalc(i);

    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r, v;
            cin >> l >> r >> v;
            l--;
            upd(l, r, -1, v);
        }
        else if(type == 2){
            int l, r, v;
            cin >> l >> r >> v;
            l--;
            upd(l, r, v, 0);
        }
        else if(type == 3){
            int l, r;
            cin >> l >> r;
            l--;
            cout << query(l, r) << '\n';
        }
        else assert(false);
    }
}
