#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MN = 1e5 + 5;
const int ME = 2e5 + 5;
int n, m;
int dsu[MN];
pair<int, pair<int, int>> edges[ME]; // {weight, {node1, node2}}

int find(int a){
    return dsu[a] < 0 ? a : dsu[a] = find(dsu[a]);
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, {a, b}};
    }
    sort(edges, edges + m);

    ll cost = 0; // cost of edges added to the MST
    int comps = n; // number of connected components
    fill_n(dsu, n, -1);
    
    for(int i = 0; i < m; i++){
        auto [c, p] = edges[i];
        auto [a, b] = p;
        a = find(a);
        b = find(b);
        if(a != b) dsu[a] = b, comps--, cost += c;
    }

    if(comps != 1) cout << "IMPOSSIBLE\n";
    else cout << cost << '\n';
}
