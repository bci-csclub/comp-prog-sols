#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)

const int MN = 105;
int n, m, w, ans;
string str;
char grid[MN][MN];
int chPos[128];

const pii MOVES[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
bool isPref[8], isSuf[8];

void check(int x, int y){
    int pos = chPos[grid[x][y]];
    if(pos == -1) return;

    FR(d, 8){
        auto [dx, dy] = MOVES[d];
        isPref[d] = pos > 0;
        int x1 = x, y1 = y;
        FORR(i, pos-1, 0){
            x1 += dx, y1 += dy;
            if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= m || grid[x1][y1] != str[i]) isPref[d] = false;
        }
        isSuf[d] = pos < w-1;
        x1 = x, y1 = y;
        FOR(i, pos+1, w){
            x1 += dx, y1 += dy;
            if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= m || grid[x1][y1] != str[i]) isSuf[d] = false;
        }
    }

    FR(d, 8){
        ans += isPref[d] && isSuf[(d+2) & 7];
        ans += isPref[d] && isSuf[(d-2) & 7];
        ans += isSuf[d] && pos == 0;
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> str;
    w = str.size();
    fill(begin(chPos), end(chPos), -1);
    FR(i, w) chPos[str[i]] = i;
    cin >> n >> m;
    FR(i, n) FR(j, m) cin >> grid[i][j];
    FR(i, n) FR(j, m) check(i, j);
    cout << ans << '\n';
}
