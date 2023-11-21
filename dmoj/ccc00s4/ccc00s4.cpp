#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;
const int MD = 5300;
const int MN = 35;
int d, n;
int dp[MD];
int clubs[MN];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> d >> n;
    for(int i = 0; i < n; i++) cin >> clubs[i];
    for(int pos = 1; pos <= d; pos++){
        dp[pos] = INF;
        for(int i = 0; i < n; i++){
            if(clubs[i] <= pos){
                dp[pos] = min(dp[pos], dp[pos-clubs[i]] + 1);
            }
        }
    }

    if(dp[d] == INF) printf("Roberta acknowledges defeat.\n");
    else printf("Roberta wins in %d strokes.\n", dp[d]);
}
