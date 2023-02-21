#include <stdio.h>
typedef unsigned int uint;
typedef long long ll;

const int MN = 1e9;
const int PW = 1162261467;
int n;

bool check(uint x){
    for(int i = 0; i < 150; i++){
        uint d = x/n;
        x -= n*d;
        if(d == 1 && x) return false;
        x *= 3;
    }
    return true;
}

void solve(int l, int r){
    int len = r-l;
    if(len > 1) solve(l, l + len/3), solve(r - len/3, r);
    else {
        int a = ((ll) l*n + PW-1)/PW;
        int b = ((ll) r*n + PW)/PW;
        for(int i = a; i < b; i++) if(check(i)) printf("%d\n", i);
    }
}

int main(){
    scanf("%d", &n);
    solve(0, PW);
}
