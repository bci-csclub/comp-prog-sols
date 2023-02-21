#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
#define pb push_back
#define fs first
#define sn second
#define ALL(v) begin(v), end(v)
#define SZ(v) ((int) (v).size())
#define ms(a, x) memset(a, x, sizeof(a))
const int INF = 0x3f3f3f3f;
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x) {cerr << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;

struct Edge {
    int a, b, d, c;

    bool operator<(const Edge &e) const {
        return c < e.c;
    }
};

const int MN = 2005;
int n, m;
pii adjMat[MN][MN];
vpii adjList[MN];
vector<Edge> zEdges, initEdges, edges;
ll dis[MN];
ll ans;

void dijkstra(int src, pii ign = {-1, -1}){
    ms(dis, INF);
    minPq<pll> pq;
    pq.push({0, src});
    dis[src] = 0;

    while(!pq.empty()){
        auto [d1, n1] = pq.top(); pq.pop();
        if(d1 != dis[n1]) continue;

        for(auto [n2, d] : adjList[n1]){
            if(pii{n1, n2} == ign || pii{n2, n1} == ign) continue;
            ll d2 = d1+d;
            if(d2 < dis[n2]) dis[n2] = d2, pq.push({d2, n2});
        }
    }
}

int dsu[MN];

int find(int a){
    return dsu[a] < 0 ? a : dsu[a] = find(dsu[a]);
}

bool merge(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return false;
    dsu[b] = a;
    return true;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    FR(i, m){
        int a, b, d, c;
        cin >> a >> b >> d >> c;
        a--; b--;
        if(!d) zEdges.pb({a, b, d, c});
        else initEdges.pb({a, b, d, c});
    }

    ms(dsu, -1);
    sort(ALL(zEdges));
    for(Edge e : zEdges) ans += merge(e.a, e.b) * e.c;

    ms(adjMat, INF);
    for(Edge e : initEdges){
        int a = find(e.a);
        int b = find(e.b);
        adjMat[a][b] = adjMat[b][a] = min(adjMat[b][a], pii{e.d, e.c});
    }

    FR(a, n) FR(b, n) if(adjMat[a][b].fs != INF){
        auto [d, c] = adjMat[a][b];
        adjList[a].pb({b, d});
        if(a < b) edges.pb({a, b, d, c});
    }

    for(Edge e : edges){
        dijkstra(e.a);
        ll dis1 = dis[e.b];
        dijkstra(e.a, {e.a, e.b});
        ll dis2 = dis[e.b];
        if(dis1 != dis2) ans += e.c;
    }

    cout << ans << '\n';
}
