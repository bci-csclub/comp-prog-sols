#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
typedef long long ll;

const int MN = 1e9;
const int PW = 1162261467;
int n;
bitset<MN> bits;
vector<int> vec;

bool check(uint x){
    for(int a : vec) bits[a] = false;
    vec.clear();
    while(true){
        uint d = x/n;
        x -= n*d;
        if(d == 1 && x) return false;
        if(bits[x]) return true;
        bits[x] = true;
        vec.push_back(x);
        x *= 3;
    }
}

void solve(int l, int r){
    int len = r-l;
    if(len > 1) solve(l, l + len/3), solve(r - len/3, r);
    else {
        int a = ((ll) l*n + PW-1)/PW;
        int b = ((ll) r*n + PW)/PW;
        for(int i = a; i < b; i++) if(check(i)) cout << i << '\n';
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    solve(0, PW);
}
