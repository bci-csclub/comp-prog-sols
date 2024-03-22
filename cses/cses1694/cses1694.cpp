#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(v) ((int) (v).size())
const int INF = 0x3f3f3f3f;

struct Edge {
    int node, cap, rev;
};

const int MN = 505;
int n, m;
vector<Edge> adjList[MN];
ll f;
int ePar[MN], mnPrv[MN], qu[MN], ql, qr;

bool bfs(){
    mnPrv[0] = INF;
    fill(ePar, ePar+n, -1);
    ql = qr = 0;
    qu[qr++] = 0;
    while(ql < qr){
        int n1 = qu[ql++];
        for(Edge e : adjList[n1]){
            if(ePar[e.node] != -1 || !e.cap) continue;
            ePar[e.node] = e.rev;
            mnPrv[e.node] = min(mnPrv[n1], e.cap);
            qu[qr++] = e.node;
        }
    }
    if(ePar[n-1] == -1) return false;
    int nf = mnPrv[n-1];
    f += nf;
    int n1 = n-1;
    while(n1){
        Edge &e = adjList[n1][ePar[n1]];
        e.cap += nf;
        adjList[e.node][e.rev].cap -= nf;
        n1 = e.node;
    }
    return true;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adjList[a].push_back({b, c, SZ(adjList[b])});
        adjList[b].push_back({a, 0, SZ(adjList[a])-1});
    }
    while(bfs());
    cout << f << '\n';
}
