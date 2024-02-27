#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6 + 5;
int n;
int arr[MN];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0;
    for(int i = 0; i < n/2; i++) ans += arr[i] == arr[i+n/2];
    cout << ans*2 << '\n';
}
