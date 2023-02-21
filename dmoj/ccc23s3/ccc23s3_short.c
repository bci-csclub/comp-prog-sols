#include <stdio.h>
#define FR(i, n) for(int i = 0; i < (n); i++)

int main(){
    int n, m, r, c;
    scanf("%d %d %d %d", &n, &m, &r, &c);
    r = n-r, c = m-c;
    if((!r && c&1 && ~m&1) || (!c && r&1 && ~n&1)) return !printf("IMPOSSIBLE\n");
    char grid[n][m+1];
    FR(i, n) FR(j, m) grid[i][j] = 'a';
    FR(i, n) grid[i][m] = '\n';
    FR(i, c/2) grid[0][i]++, grid[0][m-i-1]++;
    FR(i, r/2) grid[i][0]++, grid[n-i-1][0]++;
    grid[0][m/2] += c&1 && c != 1;
    grid[n/2][0] += r&1 && r != 1;
    grid[0][0] += r && c;
    fwrite(grid, 1, n*(m+1), stdout);
}
