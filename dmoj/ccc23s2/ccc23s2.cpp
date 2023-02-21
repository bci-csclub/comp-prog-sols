#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

const int MN = 5005;
int n;
int arr[MN], ans[MN];

void iterOut(int l, int r){
    int cur = 0;
    while(l > 0 && r < n-1){
        cur += abs(arr[--l] - arr[++r]);
        ans[r-l+1] = min(ans[r-l+1], cur);
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    fill_n(ans, n+1, INF);
    ans[1] = 0;
    for(int i = 0; i < n; i++) iterOut(i, i);
    for(int i = 0; i < n-1; i++) iterOut(i+1, i);
    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}
