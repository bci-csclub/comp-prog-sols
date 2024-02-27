#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
#define pb push_back
#define fs first
#define sn second
#define ms(a, x) memset(a, x, sizeof(a))
#define ALL(v) begin(v), end(v)
#define SZ(v) ((int) (v).size())
const int INF = 0x3f3f3f3f;
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x){cerr << #x << ' ' << (x) << endl;}
#define dbgArr(arr, n){cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}
template <typename T, typename U>
ostream& operator<<(ostream &os, pair<T, U> p){return os << "(" << p.fs << ", " << p.sn << ")";}

const int MN = 3e5 + 5;
int n, m;
int arr[MN], brr[MN], crr[MN];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FR(i, n) cin >> arr[i];
    FR(i, n) cin >> brr[i];
    FR(i, n) crr[i] = brr[i];
    m = unique(crr, crr+n) - crr;

    vi aVec;

    int ind = 0;
    FR(i, n){
        if(ind < m && arr[i] == crr[ind]){
            ind++;
            aVec.pb(i);
        }
    }

    if(ind != m) return !printf("NO\n");
    cout << "YES\n";

    int lst = -1;
    vpii bVec;
    FR(i, n){
        if(bVec.empty() || brr[i] != lst) bVec.pb({i, i});
        else bVec.back().sn = i;
        lst = brr[i];
    }
    assert(SZ(bVec) == m);

    vector<pair<char, pii>> ans;
    FR(i, m){
        int p = aVec[i];
        auto [l, r] = bVec[i];
        if(p > l) ans.pb({'L', {l, p}});
    }
    FORR(i, m-1, 0){
        int p = aVec[i];
        auto [l, r] = bVec[i];
        if(p < r) ans.pb({'R', {p, r}});
    }

    int k = SZ(ans);
    cout << k << '\n';
    for(auto [ch, p] : ans) cout << ch << ' ' << p.fs << ' ' << p.sn << '\n';
}
