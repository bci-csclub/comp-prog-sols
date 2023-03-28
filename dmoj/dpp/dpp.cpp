#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
const int MN = 1e5 + 5;
int n;
vi adjList[MN];

pii dfs(int n1, int par){
    ll v0 = 1, v1 = 1;
    for(int n2 : adjList[n1]){
        if(n2 == par) continue;
        auto [a, b] = dfs(n2, n1);
        v0 = v0 * (a+b) % MOD;
        v1 = v1 * a % MOD;
    }
    return {v0, v1};
}

int main(){
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    auto [a, b] = dfs(0, -1);
    cout << (a+b) % MOD << '\n';
}
