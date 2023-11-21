#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 5;
int n;
int arr[MN];
int dp[MN];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i < n; i++){
        dp[i] = dp[i-1] + abs(arr[i] - arr[i-1]);
        if(i >= 2) dp[i] = min(dp[i], dp[i-2] + abs(arr[i] - arr[i-2]));
    }
    cout << dp[n-1] << '\n';
}
