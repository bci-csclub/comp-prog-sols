#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

const int BSZ = 400;
const int BC = 251;
const int MN = BSZ*BC;
int n, q;
int arr[MN];
int blocks[BC];

// recalculate bi-th block
void recalc(int bi){
    int res = INF;
    for(int i = bi*BSZ; i < (bi+1)*BSZ; i++) res = min(res, arr[i]);
    blocks[bi] = res;
}

// min of [l, r)
int query(int l, int r){
    int res = INF;
    int lBlock = l/BSZ;
    int rBlock = r/BSZ;

    if(lBlock == rBlock){
        for(int i = l; i < r; i++) res = min(res, arr[i]);
        return res;
    }

    for(int i = l; i < (lBlock+1)*BSZ; i++) res = min(res, arr[i]);
    for(int i = rBlock*BSZ; i < r; i++) res = min(res, arr[i]);
    for(int i = lBlock+1; i < rBlock; i++) res = min(res, blocks[i]);
    return res;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < BC; i++) recalc(i);

    while(q--){
        char ch;
        int l, r;
        cin >> ch >> l >> r;
        if(ch == 'Q') cout << query(l, r+1) << '\n';
        else {
            arr[l] = r;
            recalc(l/BSZ);
        }
    }
}
