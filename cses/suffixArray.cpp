#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FR(i, n) for(int i = 0; i < (n); i++)

const int X = 78956244;
const int MOD = 1e9 + 7;
const int MN = 1e5 + 5;
int n;
string str;
int pws[MN], hashes[MN], sa[MN];

int lcp(int a, int b){
    int lo = 0, hi = n - max(a, b);
    while(lo < hi){
        int mid = (lo+hi+1)/2;
        ll h1 = hashes[a+mid] - (ll) pws[mid]*hashes[a];
        ll h2 = hashes[b+mid] - (ll) pws[mid]*hashes[b];
        if((h1-h2) % MOD) hi = mid-1;
        else lo = mid;
    }
    return lo;
}

bool cmp(int a, int b){
    int l = lcp(a, b);
    return str[a+l] < str[b+l];
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    pws[0] = 1;
    FR(i, MN-1) pws[i+1] = (ll) pws[i] * X % MOD;

    cin >> str;
    n = str.size();
    FR(i, n) hashes[i+1] = ((ll) hashes[i]*X + str[i]) % MOD;
    iota(sa, sa + n, 0);
    sort(sa, sa + n, cmp);

    FR(i, n) cout << sa[i] << ' ' << str.substr(sa[i]) << '\n';
}
