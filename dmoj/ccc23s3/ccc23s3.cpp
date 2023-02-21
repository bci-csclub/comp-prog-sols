#include <bits/stdc++.h>
using namespace std;
#define FR(i, n) for(int i = 0; i < (n); i++)

const int MN = 2005;
int n, m, r, c;
bool swapped;
char grid[MN][MN];

bool solve(){
    memset(grid, 'a', sizeof(grid));
    if(n == r && m == c) return true;
    if(m == c) swap(n, m), swap(r, c), swapped = true;

    if(n != r){
        FR(i, n-r) grid[i][0] = 'b';
        FR(i, m-c) grid[0][i] = 'b';
        grid[0][0] = 'c';
    }
    else {
        FR(i, (m-c)/2) grid[0][i] = grid[0][m-i-1] = 'b';
        if((m-c) & 1){
            if(m & 1) grid[0][m/2] = 'b';
            else return false;
        }
    }
    return true;
}

int main(){
    scanf("%d %d %d %d", &n, &m, &r, &c);
    if(!solve()) return !printf("IMPOSSIBLE\n");
    if(swapped){
        swap(n, m);
        FR(i, max(n, m)) FR(j, i) swap(grid[i][j], grid[j][i]);
    }
    FR(i, n) grid[i][m] = 0, puts(grid[i]);
}
