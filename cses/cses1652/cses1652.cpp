#include <bits/stdc++.h>
using namespace std;

const int MN = 1005;
int n, q;
int pref[MN][MN];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char ch; cin >> ch;
            pref[i][j] = (ch == '*') + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
    }
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        cout << (pref[x2][y2] - pref[x1][y2] - pref[x2][y1] + pref[x1][y1]) << '\n';
    }
}
