#include <bits/stdc++.h>
using namespace std;

const int MN = 505;
int n, m, k;
vector<int> adjList[MN];
int rMatch[MN]; // rMatch[r] = l means l is matched with r, where l is on left r is on right
bool vis[MN]; // for nodes on the left

bool dfs(int n1){
    vis[n1] = true;
    for(int n2 : adjList[n1]){
        int n3 = rMatch[n2];
        if(!vis[n3] && (!n3 || dfs(n3))){
            rMatch[n2] = n1;
            return true;
        }
    }
    return false;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        fill(vis, vis+MN, 0);
        ans += dfs(i);
    }
    cout << ans << '\n';
    for(int i = 1; i <= m; i++){
        if(rMatch[i]) cout << rMatch[i] << ' ' << i << '\n';
    }
}
