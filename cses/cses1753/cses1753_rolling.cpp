#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define FR(i, n) for(int i = 0; i < (n); i++)

const int X = 5878135;
const int MOD = 1e9 + 7;
int n, m;
string s1, s2;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s1 >> s2;
    n = s1.size(), m = s2.size();

    int pw = 1;
    FR(i, m) pw = (ll) pw * X % MOD;

    int keyHash = 0;
    FR(i, m) keyHash = ((ll) keyHash*X + s2[i]) % MOD;

    int strHash = 0;
    FR(i, m) strHash = ((ll) strHash*X + s1[i]) % MOD;

    int ans = keyHash == strHash;
    FR(i, n-m){
        strHash = ((ll) strHash*X + s1[i+m] - (ll) pw*s1[i]) % MOD;
        if(strHash < 0) strHash += MOD;
        ans += strHash == keyHash;
    }
    cout << ans << '\n';
}
