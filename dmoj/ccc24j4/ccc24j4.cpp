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

string s1, s2;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s1 >> s2;
    if(SZ(s1) == SZ(s2)) FR(i, SZ(s1)) if(s1[i] != s2[i]) return !printf("%c %c\n-\n", s1[i], s2[i]);
    FOR(silentCh, 'a', 'z'+1){
        set<pii> st;
        bool bad = false;
        int j = 0;
        for(char ch : s1){
            if(ch == silentCh) continue;
            if(j == SZ(s2)){
                bad = true;
                break;
            }
            if(ch != s2[j]) st.insert({ch, s2[j]});
            j++;
        }
        if(!bad && SZ(st) == 1) return !printf("%c %c\n%c\n", st.begin()->fs, st.begin()->sn, silentCh);
    }
}
