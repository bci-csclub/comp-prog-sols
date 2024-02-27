#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5 + 5;
int n, m;
vector<pair<int, int>> adjList[MN];
char ans[MN];
bool vis[MN];

void dfs(int n1, int dep){
    vis[n1] = true;
    for(auto [n2, e] : adjList[n1]){
        if(vis[n2]) continue;
        ans[e] = "BR"[dep & 1];
        dfs(n2, dep+1);
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjList[a].push_back({b, i});
        adjList[b].push_back({a, i});
    }
    for(int i = 0; i < m; i++) ans[i] = 'G';
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(i, 0);
    puts(ans);
}
