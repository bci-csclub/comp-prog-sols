#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;

struct Edge {
    int a, b, d, c;
    bool operator<(Edge e){return d != e.d ? d < e.d : c < e.c;}
};

const int MN = 2005;
int n, m;
vector<pair<int, int>> adjList[MN];
Edge edges[MN];
ll dis[MN];
minPq<pair<ll, ll>> pq;

ll dijkstra(int a, int b){
    memset(dis, INF, sizeof(dis));
    dis[a] = 0;
    pq.push({0, a});

    while(!pq.empty()){
        auto [d1, n1] = pq.top(); pq.pop();
        if(d1 != dis[n1]) continue;
        for(auto [n2, d] : adjList[n1]){
            ll d2 = d1+d;
            if(d2 < dis[n2]) dis[n2] = d2, pq.push({d2, n2});
        }
    }
    return dis[b];
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, d, c;
        cin >> a >> b >> d >> c;
        edges[i] = {--a, --b, d, c};
    }
    sort(edges, edges + m);

    ll ans = 0;
    for(int i = 0; i < m; i++){
        Edge e = edges[i];
        if(e.d < dijkstra(e.a, e.b)){
            adjList[e.a].push_back({e.b, e.d});
            adjList[e.b].push_back({e.a, e.d});
            ans += e.c;
        }
    }
    cout << ans << '\n';
}
