#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0)
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x) {cerr << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}

const int MEM = 8e5 + 5;
ll mem[MEM];
int mi;

void alloc(int sz){
    mi += sz;
    assert(mi < MEM);
}

const int MN = 2e5 + 5;
int n, q;
int arr[MN];
vi adjList[MN];
int par[MN], dep[MN], stSz[MN];

struct Seg {
    int head, tail, tsz;
    ll *tree;

    void init(){
        int sz = dep[tail] - dep[head] + 1;
        tsz = 2 << __lg(sz);
        tree = mem + mi;
        alloc(tsz*2);
    }

    ll query(int d1, int d2){
        int l = d1-dep[head], r = d2-dep[head];
        ll res = 0;
        for(l += tsz, r += tsz; l < r; l >>= 1, r >>= 1){
            if(l & 1) res += tree[l++];
            if(r & 1) res += tree[--r];
        }
        return res;
    }

    void upd(int d1, int v){
        int i = d1 - dep[head];
        for(tree[i += tsz] = v; i >>= 1;) tree[i] = tree[i*2] + tree[i*2+1];
    }
};

Seg *segs[MN];

void dfs(int n1){
    stSz[n1] = 1;
    for(int n2 : adjList[n1]) if(n2 != par[n1]){
        par[n2] = n1;
        dep[n2] = dep[n1]+1;
        dfs(n2);
        stSz[n1] += stSz[n2];
    }
}

void dfs1(int n1){
    int numCh = SZ(adjList[n1]) - (par[n1] != -1);
    if(numCh == 0){
        segs[n1] = new Seg{n1, n1};
        return;
    }

    pii mx = {-1, -1};
    for(int n2 : adjList[n1]) if(n2 != par[n1]){
        dfs1(n2);
        mx = max(mx, pii{stSz[n2], n2});
    }

    segs[n1] = segs[mx.sn];
    segs[n1]->head = n1;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    FR(i, n) cin >> arr[i];
    FR(i, n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    par[0] = -1;
    dfs(0);
    dfs1(0);

    FR(i, n) if(segs[i]->head == i) segs[i]->init();

    FR(i, n) segs[i]->upd(dep[i], arr[i]);

    while(q--){
        int type, a, x;
        cin >> type >> a;
        a--;

        if(type == 1){
            cin >> x;
            segs[a]->upd(dep[a], x);
        }
        else {
            ll res = 0;
            while(a != -1){
                res += segs[a]->query(dep[segs[a]->head], dep[a]+1);
                a = par[segs[a]->head];
            }
            cout << res << '\n';
        }
    }
}
