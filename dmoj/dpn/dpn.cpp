#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

const int MN = 405;
int n;
ll psa[MN]; // psa[i] is sum of elements in [0, i)
ll dp[MN][MN]; // dp[i][j] is min cost to merge [i, j)

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    memset(dp, INF, sizeof(dp));
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        psa[i+1] = psa[i] + a;
        dp[i][i+1] = 0;
    }
    for(int len = 2; len <= n; len++){
        for(int l = 0; l <= n-len; l++){
            int r = l+len;
            for(int i = l+1; i < r; i++){
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i][r]);
            }
            dp[l][r] += psa[r] - psa[l];
        }
    }
    cout << dp[0][n] << '\n';
}
