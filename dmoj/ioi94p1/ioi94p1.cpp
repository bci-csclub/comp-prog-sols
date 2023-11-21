#include <bits/stdc++.h>
using namespace std;

const int MN = 105;
int n;
int dp[MN][MN];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            int a; cin >> a;
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + a;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dp[n][i]);
    cout << ans << '\n';
}
