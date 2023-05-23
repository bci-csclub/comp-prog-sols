#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0)
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 64 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
 
const int MN = 2e5 + 5;
int n;
int arr[MN];
vi adjList[MN];
set<int> sets[MN];
int ans[MN];
 
void dfs(int n1, int par){
    pii mx = {-1, -1};
    for(int n2 : adjList[n1]){
        if(n2 == par) continue;
        dfs(n2, n1);
        mx = max(mx, pii{SZ(sets[n2]), n2});
    }
    if(mx.fs != -1){
        sets[n1] = move(sets[mx.sn]);
        for(int n2 : adjList[n1]){
            if(n2 == par || n2 == mx.sn) continue;
            sets[n1].insert(ALL(sets[n2]));
            sets[n2].clear();
        }
    }
    sets[n1].insert(arr[n1]);
    ans[n1] = SZ(sets[n1]);
}
 
int main(){
    boost();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
}
