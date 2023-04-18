#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define FR(i, n) for(int i = 0; i < (n); i++)

const int X = 5878135;
const int MOD = 1e9 + 7;
const int MN = 1e6 + 5;
int n, m;
string s1, s2;
int pws[MN], hashes[MN];

int getHash(int l, int r){
    int h = (hashes[r] - (ll) pws[r-l]*hashes[l]) % MOD;
    return h < 0 ? h+MOD : h;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    pws[0] = 1;
    FR(i, MN-1) pws[i+1] = (ll) pws[i] * X % MOD;
    cin >> s1 >> s2;
    n = s1.size(), m = s2.size();
    FR(i, n) hashes[i+1] = ((ll) hashes[i]*X + s1[i]) % MOD;

    ll h2 = 0;
    FR(i, m) h2 = (h2*X + s2[i]) % MOD;
    int ans = 0;
    FR(i, n-m+1) ans += h2 == getHash(i, i+m);
    cout << ans << '\n';
}
