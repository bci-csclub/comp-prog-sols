#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MN = 16;
int n, pw;
int arr[MN][MN];
ll score[1<<MN];
ll dp[1<<MN];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    pw = 1 << n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int s = 0; s < pw; s++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(((s >> i) & 1) && ((s >> j) & 1)){
                    score[s] += arr[i][j];
                }
            }
        }
    }

    for(int s = 0; s < pw; s++){
        dp[s] = score[s];
        for(int prv = (s-1) & s; prv != s; prv = (prv-1) & s){
            dp[s] = max(dp[s], dp[prv] + score[s^prv]);
        }
    }

    cout << dp[pw-1] << '\n';
}
