#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define pb push_back
const int INF = 0x3f3f3f3f;

const int MN = 18;
int n, m, pw;
vpii adjList[MN];
int dp[MN][1<<MN];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    pw = 1 << n;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].pb({b, c});
    }

    memset(dp, -INF, sizeof(dp));
    dp[0][1] = 0;

    for(int s = 0; s < pw; s++){
        for(int n1 = 0; n1 < n; n1++){
            for(auto [n2, e] : adjList[n1]){
                int ns = s | (1 << n2);
                if(ns != s) dp[n2][ns] = max(dp[n2][ns], dp[n1][s] + e);
            }
        }
    }

    cout << *max_element(dp[n-1], dp[n-1] + pw) << '\n';
}
