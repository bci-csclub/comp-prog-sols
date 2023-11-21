#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MW = 1e5 + 5;
int n, mxW;
ll oldDp[MW], newDp[MW];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> mxW;
    for(int i = 0; i < n; i++){
        memcpy(oldDp, newDp, sizeof(oldDp));
        int w, v;
        cin >> w >> v;

        for(int j = 0; j <= mxW; j++){
            if(j < w) newDp[j] = oldDp[j];
            else newDp[j] = max(oldDp[j], oldDp[j-w] + v);
        }
    }

    cout << *max_element(newDp, newDp+mxW+1) << '\n';
}
