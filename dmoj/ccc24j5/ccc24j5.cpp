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

const pii MOVES[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int MN = 1e5 + 5;
int n, m;
string grid[MN];
vector<bool> vis[MN];
int ans;

void dfs(int x1, int y1){
    if(grid[x1][y1] == 'S') ans += 1;
    if(grid[x1][y1] == 'M') ans += 5;
    if(grid[x1][y1] == 'L') ans += 10;
    vis[x1][y1] = true;
    for(auto [dx, dy] : MOVES){
        int x2 = x1+dx, y2 = y1+dy;
        if(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m || grid[x2][y2] == '*' || vis[x2][y2]) continue;
        dfs(x2, y2);
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    FR(i, n) cin >> grid[i];
    int a, b;
    cin >> a >> b;
    a--; b--;
    FR(i, n) vis[i].resize(m);
    dfs(a, b);
    cout << ans << '\n';
}
