#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
#define pb push_back
#define fs first
#define sn second
#define ms(a, x) memset(a, x, sizeof(a))
#define ALL(v) begin(v), end(v)
#define SZ(v) ((int) (v).size())
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x){cerr << #x << ' ' << (x) << endl;}
#define dbgArr(arr, n){cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}
template <typename T, typename U>
ostream& operator<<(ostream &os, pair<T, U> p){return os << "(" << p.fs << ", " << p.sn << ")";}

const int MN = 2e5 + 5;
int n;
ll arr[2][MN];

template <typename T, typename U>
void setMx(T &a, const U &b){
    a = max<T>(a, b);
}

void preproc(){
    ll num = 0;
    FR(i, 2) FR(j, n) num += arr[i][j];
    int denom = n*2;
    int g = gcd(num, denom);
    num /= g, denom /= g;
    FR(i, 2) FR(j, n) arr[i][j] *= denom, arr[i][j] -= num;
}

int v1;
map<pll, int> mp2a, mp2b;
ll offsS, offsA, offsB;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FR(i, 2) FR(j, n) cin >> arr[i][j];
    preproc();

    FR(i, n){
        ll a = arr[0][i];
        ll b = arr[1][i];

        vector<pair<pll, int>> newVs;
        if(!offsS){
            newVs.pb({{a, b}, v1+2});
            v1++;
        }
        else {
            newVs.pb({{a, offsS+b}, v1+1});
            newVs.pb({{offsS+a, b}, v1+1});
        }

        auto it = mp2a.lower_bound({-offsA, -LLINF});
        while(it != mp2a.end() && it->fs.fs == -offsA){
            auto [p, v] = *it;
            auto [x, y] = p;
            x += offsA, y += offsB;
            assert(!x);
            if(!y){
                setMx(v1, v+1);
                newVs.pb({{a, b}, v+2});
            }
            else {
                setMx(v1, v);
                newVs.pb({{a, y+b}, v+1});
            }
            ++it;
        }

        it = mp2b.lower_bound({-offsB, -LLINF});
        while(it != mp2b.end() && it->fs.fs == -offsB){
            auto [p, v] = *it;
            auto [y, x] = p;
            x += offsA, y += offsB;
            assert(!y);
            if(x){
                setMx(v1, v);
                newVs.pb({{x+a, b}, v+1});
            }
            ++it;
        }

        offsA += a;
        offsB += b;
        offsS += a+b;

        for(auto [p, v] : newVs){
            auto [x, y] = p;
            setMx(mp2a[{x-offsA, y-offsB}], v);
            setMx(mp2b[{y-offsB, x-offsA}], v);
        }
    }

    cout << max<int>(v1, mp2a[{-offsA, -offsB}]) << '\n';
}
