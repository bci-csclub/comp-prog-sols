#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 5005;
int n;
int arr[MN];
ll dp[MN][MN]; // dp[l][r] is value of [l, r)

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int len = 1; len <= n; len++){
        ll mn = LLINF;
        for(int l = 0; l <= n-len; l++){
            int r = l+len;
            dp[l][r] = dp[l+1][r-1] + abs(arr[l] - arr[r-1]);
            mn = min(mn, dp[l][r]);
        }
        cout << mn << " \n"[len == n];
    }
}
