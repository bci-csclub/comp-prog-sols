#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MN = 105;
const int MW = 1e5 + 5;
int n, mxW;
ll dp[MN][MW];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> mxW;

    for(int i = 0; i < n; i++){
        int w, v;
        cin >> w >> v;

        for(int j = 0; j <= mxW; j++){
            if(j < w) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i][j-w] + v);
        }
    }

    cout << *max_element(dp[n], dp[n]+mxW+1) << '\n';
}
