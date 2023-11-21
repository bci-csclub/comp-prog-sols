#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MW = 1e5 + 5;
int n, w;
ll dp[MW];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> w;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        for(int j = w; j >= a; j--){
            dp[j] = max(dp[j], dp[j-a] + b);
        }
    }
    cout << dp[w] << '\n';
}
